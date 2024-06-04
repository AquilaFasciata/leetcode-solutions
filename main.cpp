#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    int longestPalindrome(string s) {
      map<char, int> charMap;
      for (int i = 0; i < size(s); i++) {
        charMap[s[i]]++; 
      }
      int palinSize = 0;
      for (auto const& charItem : charMap) {
        if (charItem.second < 2) {
          continue;
        }
        else {
          palinSize += charItem.second;
        }
      }
      delete &charMap;
      return palinSize;
    }
};

int main() {
  Solution sol = Solution();
  int num = sol.longestPalindrome("abcccccdd");
  cout << "Num: " << num << '\n';
  return 0;
}
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
      vector<map<char, int>> charCounts;
      charCounts.reserve(words.size());
      for (auto const& word : words) {
        map<char, int> letterFreqMap;
        for (char const& letter : word) {
          letterFreqMap[letter]++;
        }
        charCounts.push_back(letterFreqMap);
      }
    // Right now there's a vector with a map of the frequency of each character.
    // Next, logic to check what the lowest count of each character in the arrays are;
    // then add the characters as needed to the map
    }
};

int main() {
  Solution sol = Solution();
  vector<string> vect{"cool","lock","cook"};
  vector<string> num = sol.commonChars(vect);
  vector<string> vect2{"acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"};
  vector<string> num2 = sol.commonChars(vect2);
  cout << "[ ";
  for (auto const& item : num) {
    cout << "\"" << item << "\", ";
  }
  cout << "]\n";
  cout << "[ ";
  for (auto const& item : num2) {
    cout << "\"" << item << "\", ";
  }
  return 0;
}
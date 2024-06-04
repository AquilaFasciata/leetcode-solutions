#include <string>
#include <iostream>
using namespace std;

class Solution {
  private:
    int charHash(char letter) {
      if (letter > 91) {
        return (int) (letter - 97);
      }
      else {
        return (int) (letter - 65);
      }
    }
  public:
    int longestPalindrome(string s) {
      int charCounts[26] = { 0 };
      for (int i = 0; i < size(s); i++) {
        int index = charHash(s[i]);
        charCounts[index]++;
      }
    }
};
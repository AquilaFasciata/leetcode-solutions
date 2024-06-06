#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int charHash(char letter) {
        return ((int) letter - (int) 'A');
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int> lowestCount('z' - 'A', __INT_MAX__);
        for (string const& word : words) {
            // Get the lowest count of each character in each string
            vector<int> counts(56, 0);
            for (char const& character : word) {
                    counts[charHash(character)]++;
            }
            for (int i = 0; i < counts.size(); i++) {
                if (counts[i] < lowestCount[i]) {
                    lowestCount[i] = counts[i];
                }
            }
        }

            // Build the string vector for returning
            vector<string> returnedVector;
            returnedVector.reserve(5);
            for(int i = 0; i < 'z'; i++) {
                if (lowestCount[i] > 150000) {
                    continue;
                }

                for (int j = 0; j < lowestCount[i]; j++) {
                  if (lowestCount[i] - 1 == 0) {
                    continue;
                  }
                char character = (char) (i + 'A');
                returnedVector.push_back(string(1, character));
                }
            }
            return returnedVector;
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
  cout << "]\n";
  return 0;
}
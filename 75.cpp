#include <vector>
#include <map>

class Solution {
private:
  void swapPlaces(std::vector<int>& vec, int index1, int index2) {
    vec[index1] ^= vec[index2];
    vec[index2] ^= vec[index1];
    vec[index1] ^= vec[index2];
  }
public:
  void sortColors(std::vector<int>& nums) {
    
  }
};
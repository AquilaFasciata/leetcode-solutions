#include <vector>

class Solution {
private:
  enum Color {
    RED   = 0,
    WHITE = 1,
    Blue  = 2
  };
  void swapPlaces(std::vector<int>& vec, int index1, int index2) {
    vec[index1] ^= vec[index2];
    vec[index2] ^= vec[index1];
    vec[index1] ^= vec[index2];
  }
public:
  void sortColors(std::vector<int>& nums) {

  }
}
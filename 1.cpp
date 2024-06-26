#include <cmath>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  static std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> diffMap;
    std::vector<int> indicies;
    for (int i = 0; i < nums.size(); i++) {
      if (diffMap.count(nums[i])) {
        indicies.push_back(diffMap[nums[i]]);
        indicies.push_back(i);
        break;
      } else {
        int diff = abs(target - nums[i]);
        diffMap[diff] = i;
      }
    }
    return indicies;
  }
};

int main() {
  std::vector<int> vec{3, 2, 4};
  Solution::twoSum(vec, 6);
  return 0;
}
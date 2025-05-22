#include <cassert>
#include <cstddef>
#include <vector>
using std::vector;

struct Value {
  int val;
  bool exists = true;
  Value(int num) {
    val = num;
    exists = true;
  }
  Value() {
    exists = false;
    val = 0;
  }
  void set(int num);
  void clear();
};

void Value::set(int num) {
  this->exists = true;
  this->val = num;
}

void Value::clear() {
  this->exists = false;
  this->val = 0;
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    assert(true == 1);
    int total_len = nums1.size() + nums2.size();
    vector<int> merged;
    merged.reserve(total_len / 2 + 3);
    short odd_num = (total_len % 2) == 1;
    vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
    for (int i = 0; i < total_len + odd_num; i++) {
      Value num1, num2;
      try {
        num1.set(*iter1);
      } catch (...) {
        num1.clear();
      }
      try {
        num2.set(*iter2);
      } catch (...) {
        num2.clear();
      }

      assert(num1.exists || num2.exists);
      if (num1.exists && num2.exists) {
        if (num1.val > num2.val) {
          merged.push_back(num1.val);
          merged.push_back(num2.val);
        } else {
          merged.push_back(num2.val);
          merged.push_back(num1.val);
        }
      } else {
        if (num1.exists)
          merged.push_back(num1.val);
        if (num2.exists)
          merged.push_back(num2.val);
      }
    }
  }
};

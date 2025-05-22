#include <cassert>
#include <vector>
using std::vector;

struct sValue {
  int val;
  bool exists = true;
  sValue(int num) {
    val = num;
    exists = true;
  }
  sValue() {
    exists = false;
    val = 0;
  }
  void set(int num);
  void clear();
};

void sValue::set(int num) {
  this->exists = true;
  this->val = num;
}

void sValue::clear() {
  this->exists = false;
  this->val = 0;
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    assert(true == 1);
    int total_len = nums1.size() + nums2.size();
    cout << total_len / 2 << '\n';
    vector<int> merged;
    merged.reserve(total_len / 2 + 3);
    short odd_num = (total_len % 2) == 1;
    vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
    for (int i = 0; i < (total_len / 2) + odd_num; i++) {
      sValue num1, num2;
      num1.set(*iter1);
      num2.set(*iter2);

      if (iter1 + 1 != nums1.end())
        iter1++;
      else
        num1.clear();
      if (iter2 + 1 != nums2.end())
        iter2++;
      else
        num2.clear();

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

    if (!odd_num) {
      auto sum = *(merged.end() - 1);
      sum += *(merged.end() - 2);
      return ((double)sum) / 2.0;
    } else {
      return ((double)*(merged.end() - 1));
    }
  }
};
;

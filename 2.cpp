#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream &operator<<(std::ostream &os, const ListNode *node) {
  os << "ListNode { ";
  const ListNode *current = node;
  while (current) {
    os << current->val;
    if (current->next != nullptr) {
      os << " -> ";
    }
    current = current->next;
  }
  os << " }";
  return os;
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    static ListNode *dummy_node = new ListNode(0);
    std::vector<int> sum_vec;
    sum_vec.reserve(105);
    int carry = 0;
    do {
      int val1 = l1 == nullptr ? 0 : l1->val;
      int val2 = l2 == nullptr ? 0 : l2->val;
      int sum = val1 + val2 + carry;
      carry = sum > 9 ? sum / 10 : 0;

      sum_vec.push_back(sum % 10);
      if (l1 != nullptr) {
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    } while (l1 != nullptr || l2 != nullptr);

    ListNode *list = nullptr;
    for (int i = sum_vec.size() - 1; i > -1; i--) {
      list = new ListNode(sum_vec[i], list);
    }
    return list;
  }
};

ListNode *build_list(std::vector<int> &nums) {
  ListNode *new_list = nullptr;
  for (auto num = nums.end() - 1; num != nums.begin() - 1; --num) {
    new_list = new ListNode(*num, new_list);
  }
  return new_list;
}

int main(int argc, char *argv[]) {
  Solution sol = Solution();
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> num2 = {1, 2, 3};
  ListNode *big_num = build_list(nums);
  ListNode *small = build_list(num2);
  std::cout << big_num << '\n';
  std::cout << small << '\n';
  ListNode other = ListNode(9);
  ListNode *new_nums = sol.addTwoNumbers(big_num, small);

  std::cout << new_nums;

  return 0;
}

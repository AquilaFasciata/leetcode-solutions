#include <cmath>
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
    int num1 = 0;
    int num2 = 0;
    int i = 0;
    while (l1->next != nullptr) {
      num1 += (l1->val * std::pow(10, i));
      i++;
      l1 = l1->next;
    }
    i = 0;
    while (l2->next != nullptr) {
      num1 += (l2->val * std::pow(10, i));
      i++;
      l2 = l2->next;
    }
    int result = num1 + num2;
    std::cout << "Result is " << result << '\n';
    std::string result_str = std::to_string(result);

    ListNode *new_list = new ListNode();

    for (char letter : result_str) {
      char temp_letter[] = {letter, '\0'};
      int num = std::atoi(temp_letter);
      new_list = new ListNode(num, new_list);
    }

    return new_list;
  }
};

ListNode *build_list(std::vector<int> nums) {
  ListNode *new_list = nullptr;
  for (const int num : nums) {
    new_list = new ListNode(num, new_list);
  }
  return new_list;
}

int main(int argc, char *argv[]) {
  Solution sol = Solution();
  std::vector<int> nums = {9, 9, 9, 9, 9, 9, 9, 9, 9, 1};
  std::vector<int> num2 = {9};
  ListNode *big_num = build_list(nums);
  ListNode *small = build_list(num2);
  std::cout << small << '\n';
  ListNode *new_nums = sol.addTwoNumbers(big_num, small);

  std::cout << new_nums;

  return 0;
}

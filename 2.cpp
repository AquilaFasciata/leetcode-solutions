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
    long long int num1 = 0;
    long long int num2 = 0;
    long long int i = 0;
    while (l1->next != nullptr) {
      num1 += (l1->val * std::pow(10, i));
      i++;
      l1 = l1->next;
    }
    num1 += (l1->val * std::pow(10, i));
    std::cout << "num1: " << num1 << '\n';
    i = 0;
    while (l2->next != nullptr) {
      num2 += (l2->val * std::pow(10, i));
      i++;
      l2 = l2->next;
    }
    num2 += (l2->val * std::pow(10, i));
    std::cout << "num2: " << num2 << '\n';
    long long int result = num1 + num2;
    std::cout << "The result is " << result << " \n";
    std::string result_str = std::to_string(result);

    ListNode *new_list = nullptr;

    for (char letter : result_str) {
      char temp_letter[] = {letter, '\0'};
      int num = std::atoi(temp_letter);
      if (new_list != nullptr) {
        new_list = new ListNode(num, new_list);
      } else {
        new_list = new ListNode(num);
      }
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
  std::vector<int> nums = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  std::vector<int> num2 = {4, 6, 5};
  ListNode *big_num = build_list(nums);
  ListNode *small = build_list(num2);
  std::cout << small << '\n';
  ListNode other = ListNode(9);
  ListNode *new_nums = sol.addTwoNumbers(big_num, &other);

  std::cout << new_nums;

  return 0;
}

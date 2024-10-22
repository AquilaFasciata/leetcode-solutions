#include <cmath>
#include <numeric>
#include <string>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

int main(int argc, char *argv[]) { return 0; }

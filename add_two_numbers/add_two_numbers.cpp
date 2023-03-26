// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list. You may assume the two numbers do not contain any leading zero, except
// the number 0 itself.

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using std::cout;

//  Definition for singly-linked list.
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
    auto [x1, x2] = get_values(l1, l2);

    std::string s = std::to_string(x1 + x2);
    std::reverse(s.begin(), s.end());
    ListNode *list = new ListNode(char_to_int(s[0]));
    ListNode *current = list;
    for (int i(1); i < s.length(); i++) {
      current->next = new ListNode(char_to_int(s[i]));
      current = current->next;
    }
    return list;
  }

private:
  std::string stringify_list(ListNode *list) {
    std::string result("");
    ListNode *current = list;
    while (current) {
      result += std::to_string(current->val);
      current = current->next;
    }
    return result;
  };
  std::tuple<int, int> get_values(ListNode *list1, ListNode *list2) {
    std::string s1 = stringify_list(list1);
    std::string s2 = stringify_list(list2);

    return {str_to_int(s1), str_to_int(s2)};
  }
  int str_to_int(std::string s) { return std::stoi(s); }
  int char_to_int(char c) { return c - '0'; }
};

int main() {
  ListNode el1 = ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9)))))));
  ListNode el2 = ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
  Solution solution;
  ListNode *l = solution.addTwoNumbers(&el1, &el2);
  cout << "\n";
  while (l) {
    cout << l->val << "\t";
    l = l->next;
  }
}
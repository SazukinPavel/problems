// Given head which is a reference node to a singly-linked list. The value of
// each node in the linked list is either 0 or 1. The linked list holds the
// binary representation of a number. Return the decimal value of the number in
// the linked list. The most significant bit is at the head of the linked list.

#include "iostream"
#include "stack"

using namespace std;

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
  int getDecimalValue(ListNode *head) {
    long long result = 0;

    stack<int> binaryStack;

    ListNode *curr = head;
    while (curr) {
      binaryStack.push(curr->val);
      curr = curr->next;
    }

    long long stepen = 1;
    while (!binaryStack.empty()) {
      int val = binaryStack.top();
      if (val == 1) {
        result += stepen;
      }
      binaryStack.pop();
      stepen *= 2;
    }

    return result;
  }
};

int main() {
  Solution solution;
  ListNode *list1 = new ListNode(1, new ListNode(0, new ListNode(1)));
  ListNode *list2 = new ListNode(
      1, new ListNode(
             0, new ListNode(
                    1, new ListNode(1, new ListNode(0, new ListNode(1))))));

  cout << "LIST [1,0,1] RESULT " << solution.getDecimalValue(list1) << "\n";
  cout << "LIST [1,0,1,1,0,1] RESULT " << solution.getDecimalValue(list2)
       << "\n";
}
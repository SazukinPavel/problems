// Given a linked list, swap every two adjacent nodes and return its head.
// You must solve the problem without modifying the values in the list's nodes
// (i.e., only nodes themselves may be changed.)??

#include <iostream>

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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *result = nullptr;

    ListNode *curr = head->next;
    ListNode *prev = head;
    ListNode *resultCur;

    while (prev) {
      if (curr) {
        if (!result) {
          result = new ListNode(curr->val, new ListNode(prev->val));
          resultCur = result->next;
        } else {
          resultCur->next = new ListNode(curr->val, new ListNode(prev->val));
          resultCur = resultCur->next->next;
        }
        if (curr->next && curr->next->next) {
          curr = curr->next->next;
        }else{
          curr=nullptr;
        }
        prev = prev->next->next;
      } else {
        resultCur->next = new ListNode(prev->val);
        break;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  ListNode *list1 = new ListNode(
      1,
      new ListNode(
          2, new ListNode(
                 3, new ListNode(
                        4, new ListNode(
                               5, new ListNode(
                                      6, new ListNode(7, new ListNode(8))))))));

  cout << "START LIST"
       << "\n";

  ListNode *curr = list1;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }

  ListNode *swapedList = solution.swapPairs(list1);

  cout << "\nSWAPED LIST"
       << "\n";

  curr = swapedList;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }
}
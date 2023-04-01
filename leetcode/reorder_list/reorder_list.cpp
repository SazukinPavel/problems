// You are given the head of a singly linked-list. The list can be represented
// as: L0 → L1 → … → Ln - 1 → Ln Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 →
// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.

#include "iostream"
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
  void reorderList(ListNode *head) {
    ListNode *result = new ListNode(head->val);

    ListNode *rightHead = nullptr;
    ListNode *currLeft = get_middle(head);
    ListNode *currRight = nullptr;
    ListNode *currResult = result;

    rightHead = reverse(currLeft->next);
    currLeft->next = nullptr;

    currLeft = head->next;
    currRight = rightHead;

    while (currLeft && currRight) {
      currResult->next = new ListNode(currRight->val);
      currResult->next->next = new ListNode(currLeft->val);
      currResult = currResult->next->next;
      currLeft = currLeft->next;
      currRight = currRight->next;
    }

    if (currLeft) {
      currResult->next = new ListNode(currLeft->val);
    }

    head->next = result->next;
  }

private:
  ListNode *reverse(ListNode *head) {
if(!head || !head->next){
    return head;
    }
    ListNode *curr = head;
    ListNode *prev = head->next;
    curr->next = nullptr;

    while (prev != nullptr) {
      ListNode *temp = prev->next;
      prev->next = curr;
      curr = prev;
      prev = temp;
    }
    return curr;
  }
  ListNode *get_middle(ListNode *head) {
    int middle(0);
    ListNode *curr = head;
    while (curr) {
      middle++;
      curr = curr->next;
    }
    middle = middle / 2;

    curr = head;
    for (int i(0); i < middle; i++) {
      curr = curr->next;
    }

    return curr;
  }
};

int main() {
  Solution *solution = new Solution();
//  ListNode *list = new ListNode(
//      1,
//      new ListNode(
//          2, new ListNode(
//                 3, new ListNode(
//                        4, new ListNode(
//                               5, new ListNode(
//                                      6, new ListNode(
//                                             7, new ListNode(
//                                                    8, new ListNode(
//                                                           9, new ListNode(
//                                                                  10))))))))));
  ListNode *list=new ListNode(1,new ListNode(2));
  cout << "LIST"
       << "\n";

  ListNode *curr = list;
  while (curr) {
    cout << curr->val << "\t";
    curr = curr->next;
  }

  solution->reorderList(list);

  cout << "\nREORDERD LIST"
       << "\n";
  curr = list;
  while (curr) {
    cout << curr->val << "\t";
    curr = curr->next;
  }
}
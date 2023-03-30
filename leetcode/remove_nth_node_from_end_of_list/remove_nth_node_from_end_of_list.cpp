// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *result = head;

    int indexNewLastNode(0);

    ListNode *curr = head;
    ListNode *prevCurr = head;

    while (curr) {
      if (indexNewLastNode != 0) {
        prevCurr = prevCurr->next;
      }
      indexNewLastNode++;
      curr = curr->next;
    }
    indexNewLastNode = indexNewLastNode - n;

    curr = result;
    int index = 0;
    while (curr && index + 2 < indexNewLastNode) {
      index++;
      curr = curr->next;
    }

    curr->next = prevCurr;

    return result;
  }
};

int main() {
  Solution solution;
  ListNode *list1 = new ListNode(
      0,
      new ListNode(
          3, new ListNode(
                 1, new ListNode(
                        0, new ListNode(
                               4, new ListNode(
                                      5, new ListNode(2, new ListNode(0))))))));

  cout << "START LIST"
       << "\n";

  ListNode *curr = list1;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }

  ListNode *mergedList = solution.removeNthFromEnd(list1, 3);

  cout << "\nLIST WITHOUT 3 NODES FROM END"
       << "\n";

  curr = mergedList;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }
}
// You are given the head of a linked list, which contains a series of integers
// separated by 0's. The beginning and end of the linked list will have Node.val
// == 0. For every two consecutive 0's, merge all the nodes lying in between
// them into a single node whose value is the sum of all the merged nodes. The
// modified list should not contain any 0's. Return the head of the modified
// linked list.
//

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
  ListNode *mergeNodes(ListNode *head) {
    ListNode *result = nullptr;

    ListNode *curr = head;
    ListNode *currResult = result;
    int mergedInt(0);

    while (curr) {
      if (curr->val == 0 && mergedInt != 0) {
        if (result) {
          currResult->next = new ListNode(mergedInt);
          currResult = currResult->next;
        } else {
          result = new ListNode(mergedInt);
          currResult = result;
        }
        mergedInt = 0;
      } else if (curr->val != 0) {
        mergedInt += curr->val;
      }

      curr = curr->next;
    }

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

  ListNode *mergedList = solution.mergeNodes(list1);

  cout << "\nMERGED LIST"
       << "\n";

  curr = mergedList;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }
}
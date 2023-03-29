// Given the head of a sorted linked list, delete all duplicates such that each
// element appears only once. Return the linked list sorted as well.
// The list is guaranteed to be sorted in ascending order.

#include "iostream"
#include <algorithm>
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *current = head;

    while (current) {
      if (current->next && current->val == current->next->val) {
        ListNode *next = current->next;
        while (next && next->val==current->val){
            next=next->next;
        }
        current->next=next;
      }
      current = current->next;
    }

    return head;
  }
};

int main() {
  ListNode *list1 = new ListNode(1, new ListNode(1, new ListNode(1)));

  cout << "FIRST LIST"
       << "\n";

  ListNode *curr = list1;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }

  cout << "\n";
  ListNode *noDublicateList = (new Solution())->deleteDuplicates(list1);
  cout << "NO DUBLICATE LIST"
       << "\n";

  curr = noDublicateList;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }
}

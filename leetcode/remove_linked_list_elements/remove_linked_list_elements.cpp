
// Given the head of a linked list and an integer val, remove all the nodes of
// the linked list that has Node.val == val, and return the new head.

#include "iostream"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return head;
    }

    while (head && head->val == val)
      head = head->next;

    if (!head) {
      return nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = head->next;

    while (current) {
      if (current->val == val) {
        while (next && next->val == val)
          next = next->next;
        prev->next = next;
      }
      prev = current;
      current = next;
      next = next ? next->next : nullptr;
    }

    return head;
  }
};

int main() {
  ListNode *root =
      new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
  Solution solution;
  //  ListNode *reversed = solution.removeElements(root, 5);
  ListNode *reversed = solution.removeElements(root, 2);

  cout << "BASIC LIST\n";
  ListNode *curr = reversed;
  while (curr) {
    cout << " el " << curr->val << "\t";
    curr = curr->next;
  }
}
// Given the head of a singly linked list, reverse the list, and return the
// reversed list.
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
  ListNode *reverseList(ListNode *head) {
    ListNode *copyed = copy(head);
    return reverse(copyed);
  }

private:
  ListNode *copy(ListNode *head) {
    ListNode *root = new ListNode(head->val);

    ListNode *curr = head->next;
    ListNode *currNew = root;

    while (curr) {
      currNew->next=new ListNode(curr->val);
      curr = curr->next;
      currNew=currNew->next;
    }
    return root;
  }
  ListNode *reverse(ListNode *head) {
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
};

int main() {
  ListNode *root = new ListNode(
      1, new ListNode(
             2, new ListNode(
                    3, new ListNode(4, new ListNode(5, new ListNode(6))))));
  Solution solution;
  ListNode *reversed = solution.reverseList(root);

  cout << "BASIC LIST\n";
  ListNode *curr = root;
  while (curr) {
    cout << " el " << curr->val << "\t";
    curr = curr->next;
  }

  cout << "REVERSED LIST\n";
  curr = reversed;
  while (curr) {
    cout << " el " << curr->val << "\t";
    curr = curr->next;
  }
}
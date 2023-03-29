// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing
// together the nodes of the first two lists. Return the head of the merged
// linked list.
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1 && !list2) {
      return nullptr;
    } else if (!list1 || !list2) {
      return list1 ? list1 : list2;
    }

    ListNode *newList = nullptr;
    ListNode *result = nullptr;

    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    if (list1->val <= list2->val) {
      newList = new ListNode(list1->val);
      curr1 = curr1->next;
    } else {
      newList = new ListNode(list2->val);
      curr2 = curr2->next;
    }

    result = newList;

    while (curr1 || curr2) {
      if (!curr1) {
        copy_node(newList, curr2);
        break;
      } else if (!curr2) {
        copy_node(newList, curr1);
        break;
      }

      if (node_equals(curr1, curr2)) {
        newList->next = new ListNode(curr1->val);
        newList = newList->next;
        newList->next = new ListNode(curr2->val);
        curr2 = curr2->next;
        curr1 = curr1->next;
      } else if (curr1->val < curr2->val) {
        newList->next = new ListNode(curr1->val);
        curr1 = curr1->next;
      } else {
        newList->next = new ListNode(curr2->val);
        curr2 = curr2->next;
      }
      newList = newList->next;
    }
    return result;
  }

private:
  void copy_node(ListNode *target, ListNode *copyed) {
    while (copyed) {
      target->next = new ListNode(copyed->val);
      copyed = copyed->next;
      target = target->next;
    }
  }
  bool node_equals(ListNode *n1, ListNode *n2) { return n1->val == n2->val; }
};

void printList(ListNode *root) {
  ListNode *curr = root;
  while (curr) {
    cout << "el " << curr->val << "\t";
    curr = curr->next;
  }

  cout << "\n";
}

int main() {
  ListNode *list1 = new ListNode(5);
  ListNode *list2 = new ListNode(1, new ListNode(2, new ListNode(4)));

  cout << "FIRST LIST"
       << "\n";
  printList(list1);

  cout << "SECOND LIST"
       << "\n";
  printList(list2);

  ListNode *megedList = (new Solution())->mergeTwoLists(list1, list2);
  cout << "MERGED LIST"
       << "\n";
  printList(megedList);
}

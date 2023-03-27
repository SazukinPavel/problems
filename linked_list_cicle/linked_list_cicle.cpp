//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.

//  Definition for singly-linked list.
  #include <iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x,ListNode* next) : val(x), next(next) {}
};

  class Solution {
    public:
      bool hasCycle(ListNode *head) {
        if (!head) {
          return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
          {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
              return true;
            }
          }
        }
        return false;
      };
  };

  int main(){
    Solution soluttion;
    ListNode *list=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7,new ListNode(8))))))));
    ListNode* curr=list;
    for(int i(0);i<4;i++){
      curr=curr->next;
    }
    curr->next=list;

    std::cout << soluttion.hasCycle(list);
  }
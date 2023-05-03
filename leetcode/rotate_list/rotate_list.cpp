// Given the head of a linked list, rotate the list to the right by k places.

#include "iostream"
#include <cmath>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        ListNode *curr = head;
        unsigned short index = 0;
        while (curr)
        {
            curr = curr->next;
            index++;
        }

        k -= round(k / index) * index;
        if (k == 0)
        {
            return head;
        }
        k = index - k;
        index = 1;
        curr = head;
        ListNode *currNext = head->next;
        while (index < k)
        {
            index++;
            curr = curr->next;
            currNext = currNext->next;
        }
        curr->next = nullptr;
        curr = currNext;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = head;
        return currNext;
    }
};

int main()
{
    Solution s;
    ListNode *list=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    // ListNode *list=new ListNode(1,new ListNode(2,new ListNode(0)));
    list=s.rotateRight(list,4);
    ListNode *curr=list;
    while(curr){
        cout << curr->val << "\t";
        curr = curr->next;
    }
}
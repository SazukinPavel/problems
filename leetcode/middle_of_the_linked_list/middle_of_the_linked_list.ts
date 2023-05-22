// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

//   Definition for singly-linked list.
  class ListNode {
      val: number
      next: ListNode | null
      constructor(val?: number, next?: ListNode | null) {
          this.val = (val===undefined ? 0 : val)
          this.next = (next===undefined ? null : next)
      }
  }

function middleNode(head: ListNode | null): ListNode | null {
    let length=0;
    let curr=head;
    while(curr){
        curr=curr.next;
        length++;
    }

    const mid=Math.floor(length/2);
    length=0;
    curr=head;
    while(length!=mid){
        curr=curr?.next || null;
        length++;
    }

    return curr
};
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Definition for singly-linked list.
  class ListNode {
      val: number
      next: ListNode | null
      constructor(val?: number, next?: ListNode | null) {
          this.val = (val===undefined ? 0 : val)
          this.next = (next===undefined ? null : next)
      }
  }

  function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    if(l1===null || l2===null){
        return null
    }

    const num1=+reverseString(getStringFromListNode(l1))
    const num2=+reverseString(getStringFromListNode(l2))

    return getNumericNodeByInteger(reverseString(BigInt(num1+num2)))
};

function getStringFromListNode(l: ListNode):string{
    let curr=l;
    let result=""
    while(curr){
        result+=curr.val.toString()
        curr=curr.next
    }

    return result
}

function reverseString(s:any):string{
    return s.toString().split("").reverse().join("")
}

function getNumericNodeByInteger(x:string):ListNode{
    const numeric=x.toString().split('')
    
    const result=new ListNode(+numeric[0]);
    let curr=result;
    for (let index = 1; index < numeric.length; index++) {  
        curr.next=new ListNode(+numeric[index])
        curr=curr.next;
    }

    return result
}
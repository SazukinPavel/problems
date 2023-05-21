// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

//  * Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode |
        null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    const result = new ListNode()
    while (true) {
        let min=Number.MIN_VALUE;
        for (let index = 0; index < lists.length; index++) {
            if (lists[index] != null && (lists[index] as ListNode).val < min) {
                min = (lists[index] as ListNode).val
                lists[index]=(lists[index] as ListNode).next
            }
        }

        if (min!==Number.MIN_VALUE) {
            result.next = new ListNode(min)
        } else {
            break;
        }
    }

    return result.next
};
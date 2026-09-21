# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        ptr1 = l1
        ptr2 = l2
        dummyHead = ListNode(0, None)
        ptr = dummyHead
        count = 0

        while ptr1 is not None and ptr2 is not None:
            count = ptr1.val + ptr2.val + count
            newNode = ListNode(count % 10, None)
            ptr.next = newNode
            ptr = ptr.next
            ptr1 = ptr1.next
            ptr2 = ptr2.next
            count = count // 10

        while ptr1 is not None:
            count = ptr1.val + count
            newNode = ListNode(count % 10, None)
            ptr.next = newNode
            ptr = ptr.next
            ptr1 = ptr1.next
            count = count // 10

        while ptr2 is not None:
            count = ptr2.val + count
            newNode = ListNode(count % 10, None)
            ptr.next = newNode
            ptr = ptr.next
            ptr2 = ptr2.next
            count = count // 10

        if count != 0:
            newNode = ListNode(count, None)
            ptr.next = newNode
        return dummyHead.next
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
        dummyHead = ListNode(0, None)
        ptr = dummyHead
        ptr1, ptr2 = list1, list2
        while ptr1 is not None and ptr2 is not None:
            if ptr1.val < ptr2.val:
                ptr.next = ptr1
                ptr1 = ptr1.next
            else:
                ptr.next = ptr2
                ptr2 = ptr2.next
            ptr = ptr.next
        if ptr1 is not None:
            ptr.next = ptr1
        if ptr2 is not None:
            ptr.next = ptr2
        return dummyHead.next
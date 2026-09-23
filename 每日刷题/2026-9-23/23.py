# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoList(self, list1: ListNode | None, list2: ListNode | None):
        dummyHead = ListNode()
        ptr1, ptr2, ptr = list1, list2, dummyHead
        while ptr1 and ptr2:
            if ptr1.val < ptr2.val:
                ptr.next = ptr1
                ptr1 = ptr1.next
            else:
                ptr.next = ptr2
                ptr2 = ptr2.next
            ptr = ptr.next
        if ptr1:
            ptr.next = ptr1
        if ptr2:
            ptr.next = ptr2
        return dummyHead.next

    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        head = None
        for i in range(len(lists)):
            head = self.mergeTwoList(head, lists[i])
        return head
        
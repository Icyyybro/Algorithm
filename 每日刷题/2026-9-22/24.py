# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode | None) -> ListNode | None:
        if head is None or head.next is None:
            return head
        # 递归
        node = self.swapPairs(head.next.next)
        ptr1 = head
        ptr2 = ptr1.next
        ptr2.next = ptr1
        ptr1.next = node
        return ptr2
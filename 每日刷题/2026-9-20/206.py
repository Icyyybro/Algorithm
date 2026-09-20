# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        if head == None or head.next == None:
            return head
        # 递归
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead
        

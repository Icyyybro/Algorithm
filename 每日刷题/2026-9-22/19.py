# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        dummyHead = ListNode(val=0, next=head)

        # 快指针先领先n个
        fast, slow = dummyHead, dummyHead
        for i in range(n):
            fast = fast.next
        # 一起遍历
        while fast.next is not None:
            slow = slow.next
            fast = fast.next
        # 删除
        slow.next = slow.next.next
        return dummyHead.next

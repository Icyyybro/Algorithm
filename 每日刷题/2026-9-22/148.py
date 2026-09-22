# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortTwoList(self, head1: ListNode | None, head2: ListNode | None):
        dummyHead = ListNode()
        ptr1, ptr2, ptr = head1, head2, dummyHead
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

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        # 快慢指针先找中点二分成两个链表
        slow = head
        fast = head
        pre = slow
        while fast:
            pre = slow
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
        pre.next = None
        # 两个链表递归排序
        head1 = self.sortList(head)
        head2 = self.sortList(slow)
        # 两个正序链表合并
        return self.sortTwoList(head1, head2)

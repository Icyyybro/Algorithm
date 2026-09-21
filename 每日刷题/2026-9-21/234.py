# Definition for singly-linked list.
# 1->2->3->2->1
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseListNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        nextPtr = head.next
        head.next = None
        newHead = self.reverseListNode(nextPtr)
        nextPtr.next = head
        return newHead
        

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False
        # 找到中点
        slow = head
        fast = head
        while fast is not None:
            slow = slow.next
            fast = fast.next
            if fast is not None:
                fast = fast.next

        # 反转后半链表
        head2 = self.reverseListNode(slow)

        # 遍历前半段和后半段
        ptr1 = head
        ptr2 = head2
        while ptr2 is not None:
            if ptr1.val != ptr2.val:
                return False
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        return True
        

        
        
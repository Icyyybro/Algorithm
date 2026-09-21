# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head
        while fast is not None:
            slow = slow.next
            fast = fast.next
            if fast is not None:
                fast = fast.next
                if fast == slow:
                    # 找到碰撞点，计算偏差
                    ptr = head
                    while ptr != slow:
                        ptr = ptr.next
                        slow = slow.next
                    return ptr
        return None

from collections import defaultdict

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def __init__(self):
        self.hash = {}
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return head
        if head in self.hash:
            return self.hash.get(head)
        newNode = Node(x=head.val)
        self.hash[head] = newNode
        newNode.next = self.copyRandomList(head.next)
        newNode.random = self.copyRandomList(head.random)
        return newNode
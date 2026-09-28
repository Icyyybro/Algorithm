# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        nodeList = []
        node = root
        while node or len(nodeList) != 0:
            while node:
                nodeList.append(node)
                node = node.left
            node = nodeList[-1]
            del nodeList[-1]
            k -= 1
            if k == 0:
                return node.val
            node = node.right

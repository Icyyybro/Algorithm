# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:
        if root is None:
            return 0
        list = []
        list.append(root)
        depth = 0
        while len(list) != 0:
            size = len(list)
            for i in range(size):
                node = list[0]
                if node.left is not None:
                    list.append(node.left)
                if node.right is not None:
                    list.append(node.right)
                del list[0]
            depth += 1
        return depth
            
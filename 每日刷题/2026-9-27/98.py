# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def __init__(self):
        self.pre = -inf
    def isValidBST_v1(self, root: TreeNode | None) -> bool:
        if root is None:
            return True
        # 左
        if self.isValidBST(root.left) != True:
            return False
        # 中
        if root.val <= self.pre:
            return False
        # 右
        if self.isValidBST(root.right) != True:
            return False
        self.pre = root.val
        return True

    def isValidBST(self, root: TreeNode | None) -> bool:
        if root is None:
            return True
        stack = []
        node = root
        while node or len(stack) != 0:
            while node:
                stack.append(node)
                node = node.left
            node = stack[len(stack) - 1]
            del stack[len(stack) - 1]
            if node.val <= self.pre:
                return False
            self.pre = node.val
            node = node.right
        return True
        
        
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode | None:
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        # 找到inorder中的root在哪
        idx = 0
        for i in range(len(inorder)):
            if inorder[i] == preorder[0]:
                idx = i
                break
        root.left = self.buildTree(preorder[1 : idx + 1], inorder[0 : idx])
        root.right = self.buildTree(preorder[idx + 1 :], inorder[idx + 1 :])
        return root
        
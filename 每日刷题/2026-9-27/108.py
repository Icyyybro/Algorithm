# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode | None:
        if len(nums) == 0:
            return None
        # 找root
        left, right = 0, len(nums) - 1
        mid = (left + right) // 2
        root = TreeNode(val=nums[mid])
        root.left = self.sortedArrayToBST(nums[left:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1: right + 1])
        return root
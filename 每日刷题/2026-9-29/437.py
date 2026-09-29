# Definition for a binary tree node.
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def __init__(self):
        self.table = {}
        self.cnt = 0
        self.table[0] = 1

    def dfs(self, node: TreeNode | None, preSum: int, target: int):
        if node is None:
            return
        # 先更新preSum
        preSum += node.val
        # 再更新cnt
        self.cnt += self.table.get(preSum - target, 0)
        # 更新table
        self.table[preSum] = self.table.get(preSum, 0) + 1
        # 递归
        self.dfs(node.left, preSum, target)
        self.dfs(node.right, preSum, target)
        # 退回
        self.table[preSum] = self.table.get(preSum, 0) - 1

    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.dfs(root, 0, targetSum)
        return self.cnt
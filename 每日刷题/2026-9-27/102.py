# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        nodeList = []
        ans = []
        if root is None:
            return ans
        nodeList.append(root)
        while len(nodeList) != 0:
            length = len(nodeList)
            tempList = []
            for _ in range(length):
                node = nodeList[0]
                del nodeList[0]
                if node.left:
                    nodeList.append(node.left)
                if node.right:
                    nodeList.append(node.right)
                tempList.append(node.val)
            ans.append(tempList)
        return ans
                
class Solution:
    def __init__(self):
        self.left = 0
        self.right = 0
        self.ans = []
        self.path = []

    def dfs(self, n: int):
        if self.left + self.right == 2 * n:
            self.ans.append("".join(self.path))
        # 左括号
        if self.left < n:
            self.path.append('(')
            self.left += 1
            self.dfs(n)
            self.path.pop()
            self.left -= 1
        # 右括号
        if self.right < self.left:
            self.path.append(')')
            self.right += 1
            self.dfs(n)
            self.path.pop()
            self.right -= 1

    def generateParenthesis(self, n: int) -> list[str]:
        self.dfs(n)
        return self.ans
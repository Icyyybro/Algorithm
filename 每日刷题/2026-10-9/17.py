class Solution:
    def __init__(self):
        self.table = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }
        self.ans = []
        self.str = []

    def dfs(self, i: int, digits: str):
        n = len(digits)
        if i == n:
            self.ans.append("".join(self.str))
            return
        choice = self.table[digits[i]]
        for c in choice:
            self.str.append(c)
            self.dfs(i + 1, digits)
            self.str.pop()

    def letterCombinations(self, digits: str) -> list[str]:
        self.dfs(0, digits)
        return self.ans
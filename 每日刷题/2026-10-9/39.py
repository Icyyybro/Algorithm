class Solution:
    def __init__(self):
        self.ans = []
        self.path = []
        self.left = 0

    def dfs(self, i: int, candidates: list[int]):
        if self.left == 0:
            self.ans.append(self.path.copy())
            return
        for x in range(i, len(candidates)):
            if candidates[x] > self.left:
                break
            self.path.append(candidates[x])
            self.left -= candidates[x]
            self.dfs(x, candidates)
            self.path.pop()
            self.left += candidates[x]


    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        self.left = target
        candidates.sort()
        self.dfs(0, candidates)
        return self.ans
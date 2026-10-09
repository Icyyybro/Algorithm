class Solution:
    def __init__(self):
        self.ans = []
        self.path = []
    
    def dfs(self, i: int, nums: list[int]):
        n = len(nums)
        if i == n:
            self.ans.append(self.path.copy())
            return

        # 选第i个
        self.path.append(nums[i])
        self.dfs(i + 1, nums)
        self.path.pop()
        # 不选第i个
        self.dfs(i + 1, nums)


    
    def subsets(self, nums: list[int]) -> list[list[int]]:
        self.dfs(0, nums)
        return self.ans
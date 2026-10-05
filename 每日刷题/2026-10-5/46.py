class Solution:
    def __init__(self):
        self.is_visited = [False] * 26
        self.ans = []
        self.nowList = []

    def dfs(self, idx: int, nums: list[int]):
        self.is_visited[idx] = True
        self.nowList.append(nums[idx])
        if len(self.nowList) == len(nums):
            self.ans.append(self.nowList[:])
        else:
            for i in range(len(nums)):
                if self.is_visited[i] == False:
                    self.dfs(i, nums)
        self.is_visited[idx] = False
        self.nowList.pop()

    def permute(self, nums: list[int]) -> list[list[int]]:
        for i in range(len(nums)):
            self.dfs(idx=i, nums=nums)
        return self.ans
        
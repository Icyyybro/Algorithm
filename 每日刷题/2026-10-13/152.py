class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        n = len(nums)
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0] = nums[0]
        dp[0][1] = nums[0]
        for i in range(1, n):
            num = nums[i]
            dp[i][0] = min(min(dp[i - 1][0] * num, dp[i - 1][1] * num), num)
            dp[i][1] = max(max(dp[i - 1][0] * num, dp[i - 1][1] * num), num)

        return max(dp[i][1] for i in range(n))
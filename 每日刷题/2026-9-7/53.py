class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        # 以当前数字结尾的连续数组的最大和
        dp = [0] * n
        dp[0] = nums[0]
        max_num = dp[0]
        for i in range(1, n):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
            max_num = max(max_num, dp[i])
        return max_num

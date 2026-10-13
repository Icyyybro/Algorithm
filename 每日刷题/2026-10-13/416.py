class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        sum = 0
        for num in nums:
            sum += num
        target = sum // 2
        if target * 2 != sum:
            return False

        # 0/1背包
        dp = [0] * (target + 1)
        for num in nums:
            for j in range(target, num - 1, -1):
                dp[j] = max(dp[j], dp[j - num] + num)

        if target == dp[target]:
            return True
        return False
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # 构造前缀乘法
        pre = [1] * (n + 1)
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] * nums[i - 1]
        # 构造后缀乘法
        after = [1] * (n + 1)
        for i in range(1, n + 1):
            after[i] = after[i - 1] * nums[n - i]

        ans = [1] * n
        for i in range(n):
            ans[i] = pre[i] * after[n - i - 1]
        return ans
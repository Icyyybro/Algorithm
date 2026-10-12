class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        thisStep = 0
        nextStep = 0
        cnt = 0

        for i in range(n):
            nextStep = max(nextStep, i + nums[i])

            if i == thisStep:
                # 如果可以到终点
                if thisStep >= n - 1:
                    return cnt
                # 否则跳一次
                cnt += 1
                thisStep = nextStep


        return cnt
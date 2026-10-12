class Solution:
    def canJump(self, nums: list[int]) -> bool:
        farest = nums[0]
        for i in range(len(nums)):
            if i > farest:
                return False
            farest = max(farest, i + nums[i])
        return True
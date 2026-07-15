class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        up = 0
        down = 0
        for i in range(0, len(nums) - 1):
            if nums[i + 1] > nums[i]:
                up += 1
            if nums[i + 1] < nums[i]:
                down += 1
            if up != 0 and down != 0:
                return False
            
        return True
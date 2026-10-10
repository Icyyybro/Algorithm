class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        ans = n
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                ans = mid
                return ans
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
                ans = mid
        return ans

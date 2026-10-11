class Solution:
    def findMin(self, nums: list[int]) -> int:
        n = len(nums)
        left, right = 0, n - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < nums[0]:
                right = mid - 1
            else:
                left = mid + 1

        if left == n:
            return nums[0]

        return nums[left]
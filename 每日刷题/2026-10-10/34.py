class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        if n == 0:
            return [-1, -1]

        # 先找左边
        x = 0
        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
                x = mid
        if nums[x] != target:
            return [-1, -1]

        # 再找右边
        y = 0
        left, right = x, n - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
                y = mid
            else:
                right = mid - 1
        return [x, y]
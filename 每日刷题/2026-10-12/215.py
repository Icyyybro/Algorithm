class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        last = n - 1

        def down(idx: int):
            left = idx * 2 + 1
            right = idx * 2 + 2
            bigIdx = idx
            if left <= last and nums[left] > nums[idx]:
                bigIdx = left
            if right <= last and nums[right] > nums[bigIdx]:
                bigIdx = right
            if bigIdx == idx:
                return
            else:
                tmp = nums[bigIdx]
                nums[bigIdx] = nums[idx]
                nums[idx] = tmp
                down(bigIdx)

        # 建立大根堆
        for i in range((n - 1) // 2, -1, -1):
            down(i)

        for _ in range(k - 1):
            nums[0] = nums[last]
            last -= 1
            down(0)
        return nums[0]
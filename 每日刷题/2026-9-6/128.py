class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)
        res = 0
        for num in st:
            if num-1 in st:
                continue
            target = num
            while target in st:
                target += 1
            res = max(res, target - num)
        return res
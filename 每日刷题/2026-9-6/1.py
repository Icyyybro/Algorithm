class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for i, num in enumerate(nums):
            find = target - num
            if hash.get(find, -1) != -1:
                return [hash[find], i]
            else:
                hash[num] = i
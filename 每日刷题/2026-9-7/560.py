
class Solution:
    from collections import defaultdict
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pre = [0] * (n + 1)
        table = defaultdict(int)
        count = 0
        table[0] = 1
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] + nums[i - 1]
            finding = pre[i] - k
            count += table[finding]
            table[pre[i]] += 1
        return count
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        intervals.sort(key=lambda x: x[0])
        left = intervals[0][0]
        right = intervals[0][1]
        for i, list in enumerate(intervals):
            if i == 0:
                continue
            if right < list[0]:
                ans.append([left, right])
                left = list[0]
                right = list[1]
            else:
                right = max(right, list[1])
        ans.append([left, right])
        return ans
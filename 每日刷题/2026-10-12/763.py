class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        ans = []
        table = {}
        # 找到每个字母最远的位置
        for i, c in enumerate(s):
            table[c] = i

        start = 0
        end = 0
        for i, c in enumerate(s):
            end = max(end, table[c])
            if i == end:
                ans.append(end - start + 1)
                start = end + 1
                end = end + 1
        return ans
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_num = 0
        n = len(s)
        st = set()
        j = -1
        for i in range(n):
            # 左指针向前
            if i != 0:
                st.remove(s[i - 1])
            # 右指针向前
            while j + 1 < n and s[j + 1] not in st:
                st.add(s[j + 1])
                j += 1
            max_num = max(max_num, j - i + 1)
        return max_num


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        m = len(s)
        n = len(t)
        # 哈希表
        hash = [0 for _ in range(26)]
        i = j = 0
        # 构建hash
        for i in range(m):
            hash[ord(s[i]) - ord('a')] += 1
        
        for j in range(n):
            hash[ord(t[j]) - ord('a')] -= 1
            if hash[ord(t[j]) - ord('a')] < 0:
                return t[j]
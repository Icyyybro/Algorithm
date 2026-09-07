class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = []
        len_s = len(s)
        len_p = len(p)
        hash_s = {}
        hash_p = {}
        # 录入p
        for i in range(len_p):
            hash_p[p[i]] = hash_p.get(p[i], 0) + 1

        # 滑动窗口遍历s
        for i in range(len_s):
            if i >= len_p:
                hash_s[s[i - len_p]] = hash_s.get(s[i - len_p]) - 1
                if hash_s[s[i - len_p]] == 0:
                    del hash_s[s[i - len_p]]
            hash_s[s[i]] = hash_s.get(s[i], 0) + 1
            if hash_s == hash_p:
                res.append(i - len_p + 1)
        return res

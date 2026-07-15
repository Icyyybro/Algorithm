class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        i = j = 0
        k = 0
        while j < n:
            if s[i] == s[j]:
                i += 1
            else:
                i = 0
                k = j
            j += 1
        if i == k:
            return True
        else:
            return False
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = 0
        length = 0
        for j in range(len(s)):
            if s[j] != ' ':
                length += 1
            if j < len(s) - 1 and s[j] == ' ' and s[j + 1] != ' ':
                length = 0
        return length

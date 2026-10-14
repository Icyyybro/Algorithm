class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        maxLen = 1
        begin = 0

        for l in range(1, n + 1):
            for start in range(0, n - l + 1):
                end = start + l - 1
                if s[start] != s[end]:
                    dp[start][end] = False
                elif l <= 2:
                    dp[start][end] = True
                else:
                    dp[start][end] = dp[start + 1][end - 1]

                if dp[start][end] == True:
                    maxLen = l
                    begin = start

        return s[begin : begin + maxLen]
                

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[0] = True

        def judge(word1: str, word2: str) -> bool:
            if word1 == word2:
                return True
            return False

        # dp[i] = dp[i - x] and judge
        for i in range(1, len(s) + 1):
            for word in wordDict:
                if len(word) <= i:
                    dp[i] = dp[i - len(word)] and judge(word, s[i - len(word) : i])
                    if dp[i] == True:
                        break

        return dp[len(s)]
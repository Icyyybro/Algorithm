class Solution:
    def partition(self, s: str) -> list[list[str]]:
        n = len(s)
        ans = []
        path = []
        f = [[False] * n for _ in range(n)]

        for length in range(1, n + 1):
            for start in range(0, n - length + 1):
                end = start + length - 1
                if length <= 2:
                    if s[start] == s[end]:
                        f[start][end] = True
                    else:
                        f[start][end] = False
                else:
                    if s[start] == s[end]:
                        f[start][end] = f[start + 1][end - 1]
                    else:
                        f[start][end] = False

        def dfs(i: int):
            if i == n:
                ans.append(path.copy())
                return

            for j in range(i, n):
                if f[i][j] == True:
                    path.append(s[i:j+1])
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return ans

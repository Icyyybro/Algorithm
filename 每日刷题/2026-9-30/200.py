class Solution:
    def __init__(self):
        self.dx = [-1, 1, 0, 0]
        self.dy = [0, 0, -1 ,1]
        self.cnt = 0
        self.m = 0
        self.n = 0

    def dfs(self, grid: List[List[str]], x: int, y: int):
        grid[x][y] = '0'
        for i in range(4):
            px = x + self.dx[i]
            py = y + self.dy[i]
            if px >= 0 and px < self.m and py >= 0 and py < self.n and grid[px][py] == '1':
                self.dfs(grid, px, py)

    def numIslands(self, grid: List[List[str]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == '1':
                    self.cnt += 1
                    self.dfs(grid, i, j)
        return self.cnt
        
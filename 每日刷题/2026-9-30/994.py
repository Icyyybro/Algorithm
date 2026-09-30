from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1] 
        nodeList = deque()
        left = 0
        time = 0
        # 找到所有腐烂橘子
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    nodeList.append((i, j))
                elif grid[i][j] == 1:
                    left += 1

        while len(nodeList) != 0:
            width = len(nodeList)
            for _ in range(width):
                x, y = nodeList.popleft()
                for idx in range(4):
                    px = x + dx[idx]
                    py = y + dy[idx]
                    if px >= 0 and px < m and py >= 0 and py < n and grid[px][py] == 1:
                        grid[px][py] = 2
                        left -= 1
                        nodeList.append((px, py))
            if len(nodeList) != 0:
                time += 1
        if left != 0:
            return -1
        return time


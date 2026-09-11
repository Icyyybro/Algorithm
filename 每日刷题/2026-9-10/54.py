class Solution:
    def __init__(self):
        self.dx = [0, 1, 0, -1]
        self.dy = [1, 0, -1, 0]
        self.idx = 0
        self.n = 0
        self.m = 0
        self.visited = []
    def is_legal(self, i: int, j: int) -> bool:
        if i >= 0 and i < self.n and j >= 0 and j < self.m and self.visited[i][j] is False:
            return True
        return False
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        self.n = len(matrix)
        self.m = len(matrix[0])
        self.visited = [[False] * self.m for _ in range(self.n)]
        ans = []
        cnt = 0
        i = 0
        j = 0
        while cnt < self.n * self.m:
            ans.append(matrix[i][j])
            self.visited[i][j] = True
            if self.is_legal(i + self.dx[self.idx], j + self.dy[self.idx]) is False:
                self.idx = (self.idx + 1) % 4
            i = i + self.dx[self.idx]
            j = j + self.dy[self.idx]
            cnt = cnt + 1
            
        return ans
class Solution:
    def __init__(self):
        self.path = []
        self.dx = [-1, 1, 0, 0]
        self.dy = [0, 0, -1, 1]
        self.is_visit = []
        self.m = 0
        self.n = 0
        self.flag = False

    def dfs(self, board: list[list[str]], word: str, x: int, y: int, idx: int):
        if idx == len(word) - 1:
            self.flag = True
            return
        self.is_visit[x][y] = True
        for i in range(4):
            px = x + self.dx[i]
            py = y + self.dy[i]
            if px >= 0 and px < self.m and py >= 0 and py < self.n and self.is_visit[px][py] == False and word[idx + 1] == board[px][py]:
                self.dfs(board, word, px, py, idx + 1)
        self.is_visit[x][y] = False
        

    def exist(self, board: list[list[str]], word: str) -> bool:
        # 初始化
        self.m = len(board)
        self.n = len(board[0])
        self.is_visit = [[False] * self.n for _ in range(self.m)]

        for i in range(self.m):
            for j in range(self.n):
                if board[i][j] == word[0]:
                    self.dfs(board, word, i, j, 0)
                    if self.flag == True:
                        return True
        return False

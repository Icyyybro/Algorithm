class Solution:
    def judgeCircle(self, moves: str) -> bool:
        status = [0, 0]
        for i, move in enumerate(moves):
            if move == 'U':
                status[1] += 1
            elif move == 'D':
                status[1] -= 1
            elif move == 'R':
                status[0] += 1
            else:
                status[0] -= 1
        if status[0] == 0 and status[1] == 0:
            return True
        else:
            return False
            

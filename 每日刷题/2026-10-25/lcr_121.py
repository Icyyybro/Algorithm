class Solution:
    def findTargetIn2DPlants(self, plants: List[List[int]], target: int) -> bool:
        # 从右上角开始选
        m = len(plants)
        if m == 0:
            return False
        n = len(plants[0])

        x, y = 0, n - 1
        while x >= 0 and x < m and y >= 0 and y < n:
            if plants[x][y] == target:
                return True
            elif plants[x][y] < target:
                    x += 1
            else:
                    y -= 1
        return False
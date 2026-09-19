class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        # 从右上角开始排出
        i = 0
        j = n - 1
        while i < m and j >= 0:
            if matrix[i][j] == target:
                return True
            # 如果右上角小于target，排除这一行
            elif matrix[i][j] < target:
                i += 1
            # 如果右上角大于target，排除这一列
            else:
                j -= 1
        return False
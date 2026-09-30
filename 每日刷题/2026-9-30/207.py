class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        # 建图
        graph = [[] for _ in range(numCourses)]
        for item in prerequisites:
            graph[item[0]].append(item[1])
        # color有三个颜色: 0未访问；1正在访问；2访问完成
        color = [0] * numCourses

        # 判断x出发是否成环
        def dfs(x: int):
            color[x] = 1
            for y in graph[x]:
                if color[y] == 1 or (color[y] == 0 and dfs(y)):
                    return True
            color[x] = 2
            return False

        for i, c in enumerate(color):
            if c == 0 and dfs(i):
                return False
        return True
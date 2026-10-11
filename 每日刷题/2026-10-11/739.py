class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        # 栈中记录还没计算出来温度的下标
        stack = []
        n = len(temperatures)
        ans = [0] * n
        
        i = 0
        while i < n:
            while len(stack) != 0 and temperatures[stack[-1]] < temperatures[i]:
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
            i += 1

        return ans
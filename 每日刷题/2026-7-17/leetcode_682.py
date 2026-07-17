from typing import List


class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack = []

        for operation in operations:
            if operation == "+":
                stack.append(stack[-1] + stack[-2])
            elif operation == "D":
                stack.append(stack[-1] * 2)
            elif operation == "C":
                stack.pop()
            else:
                # 剩余情况一定是整数，包括负数和多位整数
                stack.append(int(operation))

        return sum(stack)
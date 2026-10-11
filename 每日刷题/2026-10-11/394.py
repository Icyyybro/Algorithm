from collections import deque
class Solution:
    def decodeString(self, s: str) -> str:
        numStack = []
        strStack = []
        n = len(s)
        i = 0
        while i < n:
            # 数字
            if s[i] >= '0' and s[i] <= '9':
                # 找到完整数字
                total = 0
                while s[i] >= '0' and s[i] <= '9':
                    total *= 10
                    total += ord(s[i]) - ord('0')
                    i += 1
                # 退一格
                i -= 1
                numStack.append(total)
            # 右括号
            elif s[i] == ']':
                strQue = deque()
                while strStack[-1] != "[":
                    strQue.appendleft(strStack.pop())
                # 左括号出栈
                strStack.pop()
                originString = "".join(strQue)
                # 循环拼接多个string
                string = []
                num = numStack.pop()
                for _ in range(num):
                    string.append(originString)
                strStack.append("".join(string))
            # 左括号和字符
            else:
                strStack.append(str(s[i]))
            i += 1

        return "".join(strStack)

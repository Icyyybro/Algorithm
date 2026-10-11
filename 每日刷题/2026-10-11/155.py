class MinStack:

    def __init__(self):
        self.minStack = []
        self.stack = []

    def push(self, value: int) -> None:
        self.stack.append(value)
        if len(self.minStack) != 0 and self.minStack[-1] < value:
            self.minStack.append(self.minStack[-1])
        else:
            self.minStack.append(value)

    def pop(self) -> None:
        self.minStack.pop()
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
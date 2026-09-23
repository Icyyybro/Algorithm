class DListNode:
    def __init__(self, pre = None, next = None, key = 0, val = 0):
        self.pre = pre
        self.next = next
        self.key = key
        self.val = val

class LRUCache:

    def __init__(self, capacity: int):
        self.hash = {}
        self.dummyHead = DListNode()
        self.dummyTail = DListNode()
        self.dummyHead.next = self.dummyTail
        self.dummyTail.pre = self.dummyHead
        self.capacity = capacity
        self.num = 0

    def delete(self, node: DListNode):
        pre = node.pre
        after = node.next
        pre.next = after
        after.pre = pre

    def insertToFirst(self, node: DListNode):
        preFirstNode = self.dummyHead.next
        self.dummyHead.next = node
        node.pre = self.dummyHead
        node.next = preFirstNode
        preFirstNode.pre = node


    def get(self, key: int) -> int:
        # 先判断是否存在key
        if key not in self.hash:
            return -1
        # 存在，将其移动到首
        node = self.hash[key]
        self.delete(node)
        self.insertToFirst(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        # 先判断是否存在
        if key in self.hash:
            node = self.hash[key]
            node.val = value
            self.delete(node)
            self.insertToFirst(node)
            return
        # 如果不存在，先判断是否超capacity
        if self.num == self.capacity:
            # 如果超了，先删除最后一个
            del self.hash[self.dummyTail.pre.key]
            self.delete(self.dummyTail.pre)
            self.num -= 1
        # 插入新的
        newNode = DListNode(val=value, key=key)
        self.hash[key] = newNode
        self.insertToFirst(newNode)
        self.num += 1


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
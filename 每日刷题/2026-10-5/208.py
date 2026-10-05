class TrieNode:
    def __init__(self):
        self.next = [None] * 26
        self.is_end = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        length = len(word)
        node = self.root
        for _, c in enumerate(word):
            idx = ord(c) - ord('a')
            if node.next[idx] is None:
                newNode = TrieNode()
                node.next[idx] = newNode
            node = node.next[idx]
        # 最后一个node打上终止符号
        node.is_end = True
        

    def search(self, word: str) -> bool:
        length = len(word)
        node = self.root
        for _, c in enumerate(word):
            idx = ord(c) - ord('a')
            if node.next[idx] is None:
                return False
            node = node.next[idx]
        if node.is_end == False:
            return False
        return True
        

    def startsWith(self, prefix: str) -> bool:
        length = len(prefix)
        node = self.root
        for _, c in enumerate(prefix):
            idx = ord(c) - ord('a')
            if node.next[idx] is None:
                return False
            node = node.next[idx]
        return True
            
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
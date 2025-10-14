class LRUCache {
    public class DLNode {
        DLNode left;
        DLNode right;
        int key;
        int value;
        public DLNode() {}
        public DLNode(int k, int v) {
            key = k;
            value = v;
        }
    }
    Map<Integer, DLNode> map;
    DLNode dummyHead;
    DLNode dummyTail;
    int maxSize;
    int num;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        dummyHead = new DLNode();
        dummyTail = new DLNode();
        dummyHead.right = dummyTail;
        dummyTail.left = dummyHead;
        maxSize = capacity;
        num = 0;
    }
    
    public int get(int key) {
        DLNode node = map.getOrDefault(key, null);
        if(node == null)
            return -1;
        deleteInList(node);
        putInFirst(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        DLNode node = map.getOrDefault(key, null);
        // 如果node存在
        if(node != null) {
            node.value = value;
            deleteInList(node);
            putInFirst(node);
            return;
        }
        // 如果node不存在
        node = new DLNode(key, value);
        map.put(key, node);
        // 如果满了
        if(maxSize == num) {
            map.remove(dummyTail.left.key);
            deleteInList(dummyTail.left);
            putInFirst(node);
            num--;
        }
        // 如果没满
        else {
            putInFirst(node);
        }
        num++;
    }

    private void deleteInList(DLNode node) {
        DLNode pre = node.left;
        DLNode next = node.right;
        pre.right = next;
        next.left = pre;
    }

    private void putInFirst(DLNode node) {
        DLNode next = dummyHead.right;
        node.left = dummyHead;
        node.right = next;
        dummyHead.right = node;
        next.left = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
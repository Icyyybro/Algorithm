/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;3

        next = NULL;
        random = NULL;
    }
};
*/

// 方法1：回溯+哈希表
class Solution
{
public:
    unordered_map<Node *, Node *> hash;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (hash.count(head) == 0)
        {
            Node *newnode = new Node(head->val);
            hash[head] = newnode;
            newnode->next = copyRandomList(head->next);
            newnode->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};

// 方法2：迭代+节点拆分
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *newnode = new Node(node->val);
            newnode->next = node->next;
            node->next = newnode;
        }
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *newnode = node->next;
            newnode->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node *newhead = head->next;
        for (Node *node = head; node != nullptr; node = node->next)
        {
            Node *newnode = node->next;
            node->next = node->next->next;
            newnode->next = (newnode->next) ? newnode->next->next : nullptr;
        }

        return newhead;
    }
};
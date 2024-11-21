# N叉树前序遍历

题目链接：[https://leetcode.cn/problems/n-ary-tree-preorder-traversal](https://leetcode.cn/problems/n-ary-tree-preorder-traversal "https://leetcode.cn/problems/n-ary-tree-preorder-traversal")

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pre(Node* node, vector<int>& ans)
    {
        if(node == nullptr)
            return;
        ans.push_back(node -> val);
        for(auto it: node -> children)
            pre(it, ans);
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};
```

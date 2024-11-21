# N叉树的后序遍历

题目链接：[https://leetcode.cn/problems/n-ary-tree-postorder-traversal](https://leetcode.cn/problems/n-ary-tree-postorder-traversal "https://leetcode.cn/problems/n-ary-tree-postorder-traversal")

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }

    void post(Node* node, vector<int>& ans)
    {
        if(node == nullptr)
            return;
        for(auto it: node -> children)
            post(it, ans);
        ans.push_back(node -> val);
    }
};
```

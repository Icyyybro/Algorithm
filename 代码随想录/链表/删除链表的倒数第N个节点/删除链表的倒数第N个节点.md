# 删除链表的倒数第N个节点

# 1. 题目

题目链接：[https://leetcode.cn/problems/remove-nth-node-from-end-of-list](https://leetcode.cn/problems/remove-nth-node-from-end-of-list "https://leetcode.cn/problems/remove-nth-node-from-end-of-list")

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

![](image/remove_ex1_vgUymwmjJm.jpg)

# 2. 算法

使用快慢指针，快指针先走n - 1步，同时本题为了防止删除头节点时特殊处理，需要设置虚拟头节点。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        int count = 0;
        while(count < n)
        {
            fast = fast -> next;
            count++;
        }
        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return dummyHead -> next;
    }
};
```

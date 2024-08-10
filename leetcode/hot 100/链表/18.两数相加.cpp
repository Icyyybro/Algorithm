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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        ListNode *l3 = new ListNode();
        ListNode *node3 = l3;
        int cnt = 0;
        while (node1 && node2)
        {
            cnt = node1->val + node2->val + cnt;
            node1 = node1->next;
            node2 = node2->next;
            ListNode *newnode = new ListNode();
            newnode->val = cnt % 10;
            cnt /= 10;
            node3->next = newnode;
            node3 = newnode;
        }
        while (node1)
        {
            cnt = node1->val + cnt;
            node1 = node1->next;
            ListNode *newnode = new ListNode();
            newnode->val = cnt % 10;
            cnt /= 10;
            node3->next = newnode;
            node3 = newnode;
        }
        while (node2)
        {
            cnt = node2->val + cnt;
            node2 = node2->next;
            ListNode *newnode = new ListNode();
            newnode->val = cnt % 10;
            cnt /= 10;
            node3->next = newnode;
            node3 = newnode;
        }
        if (cnt)
        {
            ListNode *newnode = new ListNode();
            newnode->val = cnt % 10;
            cnt /= 10;
            node3->next = newnode;
            node3 = newnode;
        }
        return l3->next;
    }
};
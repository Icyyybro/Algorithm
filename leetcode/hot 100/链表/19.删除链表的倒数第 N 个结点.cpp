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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        unordered_map<int, ListNode *> hash;
        ListNode *node = head;
        int cnt = 1;
        while (node)
        {
            hash[cnt] = node;
            node = node->next;
            cnt++;
        }
        int pos = cnt - n;
        if (pos == 1)
            return head->next;
        else
        {
            int pre = pos - 1;
            ListNode *pre_node = hash[pre];
            pre_node->next = hash[pos]->next;
        }
        return head;
    }
};
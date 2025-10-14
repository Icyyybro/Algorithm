/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        ListNode node1 = head;
        ListNode node2 = head.next;
        ListNode nxt = swapPairs(node2.next);
        node2.next = node1;
        node1.next = nxt;
        return node2;
    }
}
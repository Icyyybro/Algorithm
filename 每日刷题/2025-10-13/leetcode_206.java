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
    public ListNode reverseList(ListNode head) {
        if(head == null)
            return null;
        ListNode node1 = null;
        ListNode node2 = head;
        while(node2 != null) {
            ListNode nxt = node2.next;
            node2.next = node1;
            node1 = node2;
            node2 = nxt;
        }
        return node1;
    }
}
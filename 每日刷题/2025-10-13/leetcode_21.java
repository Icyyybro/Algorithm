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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode node1 = list1;
        ListNode node2 = list2;
        ListNode dummyHead = new ListNode();
        ListNode node = dummyHead;

        while(node1 != null && node2 != null) {
            ListNode newNode = new ListNode();
            if(node1.val > node2.val) {
                newNode.val = node2.val;
                node2 = node2.next;
            }
            else {
                newNode.val = node1.val;
                node1 = node1.next;
            }
            node.next = newNode;
            node = node.next;
        }
        if(node1 != null)
            node.next = node1;
        if(node2 != null)
            node.next = node2;
        return dummyHead.next;
    }
}
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
    public ListNode sortList(ListNode head) {
        return mergeSort(head, null);
    }

    private ListNode mergeSort(ListNode head, ListNode end) {
        if(head == end)
            return null;
        if(head.next == end) {
            head.next = null;
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        while(fast != end) {
            slow = slow.next;
            fast = fast.next;
            if(fast != end)
                fast = fast.next;
        }
        ListNode list1 = mergeSort(head, slow);
        ListNode list2 = mergeSort(slow, end);
        ListNode dummyHead = new ListNode();
        ListNode node = dummyHead;
        ListNode node1 = list1;
        ListNode node2 = list2;
        while(node1 != null && node2 != null) {
            if(node1.val > node2.val) {
                node.next = node2;
                node2 = node2.next;
            }
            else {
                node.next = node1;
                node1 = node1.next;
            }
            node = node.next;
        }
        if(node1 != null)
            node.next = node1;
        if(node2 != null)
            node.next = node2;
        return dummyHead.next;
    }
}

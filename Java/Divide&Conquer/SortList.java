// https://leetcode.com/problems/sort-list/


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
        if (head == null || head.next == null) return head;
        ListNode mid = getMid(head);
        ListNode l = sortList(head);
        ListNode r = sortList(mid);
        return merge(l, r);
    }
    
    public ListNode getMid(ListNode head) {
        ListNode p1 = head, p2 = head.next;
        while (p2.next != null && p2.next.next!= null) {
            p2 = p2.next.next;
            p1 = p1.next;
        }
        ListNode ret = p1.next;
        p1.next = null;
        return ret;
    } 
    
    public ListNode merge(ListNode l, ListNode r) {
        ListNode ret = new ListNode(-1);
        ListNode p = ret;
        while (l != null && r != null) {
            if (l.val < r.val) {
                p.next = l;
                l = l.next;
            }
            else {
                p.next = r;
                r = r.next;
            }
            p = p.next;
        }
        if (l != null) {
            p.next = l;
        }
        if (r != null) {
            p.next = r;
        }
        return ret.next;
    }
}

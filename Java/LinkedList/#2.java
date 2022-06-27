// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ret = new ListNode(-1);
        ListNode p = ret;
        int carry = 0, val = 0;
        while (l1 != null && l2 != null) {
            val = carry + l1.val + l2.val;
            carry = val / 10;
            val %= 10;
            p.next = new ListNode(val);
            p = p.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            val = carry + l1.val;
            carry = val / 10;
            val %= 10;
            p.next = new ListNode(val);
            p = p.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            val = carry + l2.val;
            carry = val / 10;
            val %= 10;
            p.next = new ListNode(val);
            p = p.next;
            l2 = l2.next;
        }
        if (carry == 1) p.next = new ListNode(1);
        return ret.next;
        
    }
}

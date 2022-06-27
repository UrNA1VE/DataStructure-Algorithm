# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        ret = ListNode()
        p = ret
        while l1 is not None and l2 is not None:
            value = l1.val + l2.val + carry
            node = ListNode(value % 10)
            carry = value // 10
            p.next = node
            p = p.next
            l1 = l1.next
            l2 = l2.next
            
        while l1 is not None:
            value = l1.val + carry
            node = ListNode(value % 10)
            carry = value // 10
            p.next = node
            p = p.next
            l1 = l1.next

        while l2 is not None:
            value = l2.val + carry
            node = ListNode(value % 10)
            carry = value // 10
            p.next = node
            p = p.next
            l2 = l2.next
            
        if carry == 1:
            p.next = ListNode(1)
        return ret.next

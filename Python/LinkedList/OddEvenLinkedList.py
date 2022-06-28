# https://leetcode.com/problems/odd-even-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        slow = head
        fast = head.next
        while fast and fast.next:
            oddend = fast.next
            evenstart = slow.next
            nex = oddend.next
            slow.next = oddend
            oddend.next = evenstart
            fast.next = nex
            slow = slow.next
            fast = fast.next
        return head

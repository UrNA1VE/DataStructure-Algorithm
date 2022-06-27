# https://leetcode.com/problems/partition-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        left_head = ListNode(-300)
        left_end = left_head
        right_head = ListNode(-300)
        right_end = right_head
        while head is not None:
            if head.val < x:
                left_end.next = ListNode(head.val)
                left_end = left_end.next
            if head.val >= x:
                right_end.next = ListNode(head.val)
                right_end = right_end.next
            head = head.next
        left_end.next = right_head.next
        return left_head.next

# https://leetcode.com/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        p = head
        count = 1
        while p.next is not None:
            count += 1
            p = p.next
        p.next = head
        k = k % count
        for i in range(count - k):
            head = head.next
            p = p.next
        p.next = None
        return head

# https://leetcode.com/problems/reverse-linked-list-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if head is None:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        pos = 1
        current = dummy
        while pos < m:
            pos += 1
            current = current.next
        next = current.next
        while m < n:
            temp = next.next
            next.next = temp.next
            temp.next = current.next
            current.next = temp
            m += 1
        return dummy.next

        return head

# https://leetcode.com/problems/palindrome-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        rev = None
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, head = head, rev, head.next
        if not rev:
            return True
        tail = rev
        head = head.next if fast else head
        while tail and head:
            if tail.val != head.val:
                return False
            head, tail = head.next, tail.next
        return True

# https://leetcode.com/problems/add-two-numbers-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def get_num(l):
            res = 0
            while l:
                res = res * 10 + l.val
                l = l.next
            return res
        num1 = get_num(l1)
        num2 = get_num(l2)
        def become_l(num):
            res = []
            while num >= 10:
                residue = num % 10
                res.insert(0, residue)
                num = num // 10
            res.insert(0, num)
            head = ListNode(res[0])
            p = head
            for i in range(1, len(res)):
                p.next = ListNode(res[i])
                p = p.next
            return head
        return become_l(num1 + num2)

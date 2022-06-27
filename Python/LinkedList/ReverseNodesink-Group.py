# https://leetcode.com/problems/reverse-nodes-in-k-group/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        p = head
        length = 0
        while p is not None:
            length += 1
            p = p.next

        all_count = 0
        end = head
        p = 0
        res = head
        last = 0
        while all_count < length:
            start = end
            pre = end
            nextn = end
            end = end.next
            all_count += 1
            if length - all_count >= k - 1:
                for i in range(k - 1):
                    pre = nextn
                    nextn = end
                    end = end.next
                    nextn.next = pre
                    start.next = end
                    all_count += 1
                if p == 0:
                    res = nextn
                    p = 1
                    last = start
                elif p == 1:
                    last.next = nextn
                    last = start
                    
        return res

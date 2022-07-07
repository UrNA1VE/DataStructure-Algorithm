# https://leetcode.com/problems/spiral-matrix-iv/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        up, down, left, right = 0, m - 1, 0, n - 1
        ret = [[0] * n for _ in range(m)]
        while up < down and left < right:
            
            for j in range(left, right):
                val = -1
                if head is not None:
                    val = head.val
                    head = head.next
                ret[up][j] = val
                
            for i in range(up, down):
                val = -1
                if head is not None:
                    val = head.val
                    head = head.next
                ret[i][right] = val
        
            for j in range(right, left, -1):
                val = -1
                if head is not None:
                    val = head.val
                    head = head.next
                ret[down][j] = val

            for i in range(down, up, -1):
                val = -1
                if head is not None:
                    val = head.val
                    head = head.next
                ret[i][left] = val
            up += 1
            down -= 1
            left += 1
            right -= 1
            
        if up == down:
            for j in range(left, right + 1):
                val = -1
                if head is not None:
                    val = head.val
                    head = head.next
                ret[up][j] = val
        elif left == right:    
            for i in range(up, down + 1):
                val = -1
                if head is not None:
                    val = head.val
                    head = head.next
                ret[i][right] = val
        return ret

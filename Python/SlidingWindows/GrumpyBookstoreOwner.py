# https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        normal = 0
        for i in range(len(customers)):
            normal += abs(grumpy[i] - 1) * customers[i]
        left = 0
        right = 0
        used = 0
        res = 0
        now = 0
        while right < len(grumpy):
            if used < X:
                now += grumpy[right] * customers[right]
                used += 1
                right += 1
            else:
                res = max(now, res)
                now += grumpy[right] * customers[right]
                now -= grumpy[left] * customers[left]
                right += 1
                left += 1
        res = max(res, now)
        return res + normal

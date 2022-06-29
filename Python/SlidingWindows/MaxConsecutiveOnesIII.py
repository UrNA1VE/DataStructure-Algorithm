# https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        left = 0
        right = 0
        used = 0
        res = 0
        while right < len(A):
            if A[right] == 1:
                right += 1
                continue
            elif A[right] == 0:
                if used < K:
                    right += 1
                    used += 1
                    continue
                else:
                    res = max(res, right - left)
                    while A[left] == 1:
                        left += 1
                    left += 1
                    right += 1
                    continue
        res = max(res, right - left)
        return res

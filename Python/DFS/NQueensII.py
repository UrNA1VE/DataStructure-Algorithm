# https://leetcode.com/problems/n-queens-ii/

class Solution:
    def totalNQueens(self, n: int) -> int:
        res = 0
        cols = [0] * n
        left = [0] * (2 * n - 1)
        right = [0] * (2 * n - 1)
        def helper(i):
            nonlocal res, cols, left, right
            if i == n:
                res += 1
                return
            else:
                for j in range(n):
                    if cols[j] == 0 and left[i + j] == 0 and right[i - j + n - 1] == 0:
                        cols[j] = 1
                        left[i + j] = 1
                        right[i - j + n - 1] = 1
                        helper(i + 1)
                        cols[j] = 0
                        left[i + j] = 0
                        right[i - j + n - 1] = 0
        helper(0)
        return res

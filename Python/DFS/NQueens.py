# https://leetcode.com/problems/n-queens/

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        cols = [0] * n
        left = [0] * (2 * n - 1)
        right = [0] * (2 * n - 1)
        ans = [0] * n
        def helper(i):
            nonlocal res, cols, left, right, ans
            if i == n:
                solutions = []
                for row, col in enumerate(ans):
                    l = col
                    r = n - 1 - col
                    solution = '.' * l + 'Q' + '.' * r
                    solutions.append(solution)
                res.append(solutions)
                return
            else:
                for j in range(n):
                    if cols[j] == 0 and left[i + j] == 0 and right[i - j + n - 1] == 0:
                        cols[j] = 1
                        left[i + j] = 1
                        right[i - j + n - 1] = 1
                        ans[i] = j
                        helper(i + 1)
                        cols[j] = 0
                        left[i + j] = 0
                        right[i - j + n - 1] = 0
                        ans[i] = 0
        helper(0)
        return res

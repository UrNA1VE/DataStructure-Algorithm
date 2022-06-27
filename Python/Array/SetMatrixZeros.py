# https://leetcode.com/problems/set-matrix-zeroes/

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        inf = float('inf')
        rows = len(matrix)
        cols = len(matrix[0])
        def helper(i, j):
            for k in range(rows):
                if matrix[k][j] != 0:
                    matrix[k][j] = inf
            for k in range(cols):
                if matrix[i][k] != 0:
                    matrix[i][k] = inf
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    helper(i, j)
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == inf:
                    matrix[i][j] = 0
        return 
        """
        Do not return anything, modify matrix in-place instead.
        """
        

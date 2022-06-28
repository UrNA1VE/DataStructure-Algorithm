# https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution:
    def searchMatrix(self, matrix, target):
        if matrix == [[]] or matrix == []:
            return False
        size = len(matrix)
        n = len(matrix[0])
        for i in range(size):
            if matrix[i][0] > target or matrix[i][n - 1] < target:
                continue
            for j in range(n):
                if matrix[i][j] == target:
                    return True
        return False
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        

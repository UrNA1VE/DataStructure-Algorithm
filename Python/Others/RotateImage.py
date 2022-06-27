# https://leetcode.com/problems/rotate-image/

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        for i in range(0, len(matrix)// 2):
            for j in range(0, (len(matrix) + 1) // 2):
                matrix[i][j], matrix[j][~i], matrix[~i][~j], matrix[~j][i] =  matrix[~j][i], matrix[i][j], matrix[j][~i], matrix[~i][~j]
        return

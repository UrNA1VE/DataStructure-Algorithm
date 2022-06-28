# https://leetcode.com/problems/01-matrix/ 
 
 class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        res = [[0] * len(matrix[0]) for i in range(len(matrix))]
        def helper(i, j):
            count = 0
            process.append((i, j))
            process.append('*')
            while process:
                if process == ['*']:
                    return
                if process[0] == '*':
                    count += 1
                    process.append('*')
                    process.pop(0)
                    continue
                x, y = process.pop(0)
                dic.append((x, y))
                if matrix[x][y] == 0:
                    return count
                points = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
                for xx, yy in points:
                    if 0 <= xx < len(matrix) and 0 <= yy < len(matrix[0]) and (xx, yy) not in dic:
                        process.append((xx, yy))

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                dic = []
                process = []
                res[i][j] = helper(i, j)
        return res

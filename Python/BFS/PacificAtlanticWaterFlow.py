# https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix:
            return []
        res = []
        dp_pac = [[0] * len(matrix[0]) for _ in range(len(matrix))]
        dp_atl = [[0] * len(matrix[0]) for _ in range(len(matrix))]
        for i in range(len(matrix)):
            dp_pac[i][0] = 1
            dp_atl[i][-1] = 1
        for i in range(len(matrix[0])):
            dp_pac[0][i] = 1
            dp_atl[-1][i] = 1

        def bfs_pac(i, j):
            nonlocal dp_pac
            process = [(i, j)]
            while process:
                x, y = process.pop(0)
                directions = [(x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1)]
                for xx, yy in directions:
                    if xx < 0 or xx >= len(matrix) or yy < 0 or yy >= len(matrix[0]):
                        continue
                    elif matrix[xx][yy] < matrix[x][y] or dp_pac[xx][yy] == 1:
                        continue
                    elif matrix[xx][yy] >= matrix[x][y]:
                        dp_pac[xx][yy] = 1
                        process.append((xx, yy))

        def bfs_atl(i, j):
            nonlocal dp_atl
            process = [(i, j)]
            while process:
                x, y = process.pop(0)
                directions = [(x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1)]
                for xx, yy in directions:
                    if xx < 0 or xx >= len(matrix) or yy < 0 or yy >= len(matrix[0]):
                        continue
                    elif matrix[xx][yy] < matrix[x][y] or dp_atl[xx][yy] == 1:
                        continue
                    elif matrix[xx][yy] >= matrix[x][y]:
                        dp_atl[xx][yy] = 1
                        process.append((xx, yy))

        for i in range(len(matrix)):
            bfs_pac(i, 0)
        for i in range(len(matrix[0])):
            bfs_pac(0, i)
        for i in range(len(matrix)):
            bfs_atl(i, len(matrix[0]) - 1)
        for i in range(len(matrix[0])):
            bfs_atl(len(matrix) - 1, i)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if dp_pac[i][j] == 1 and dp_atl[i][j] == 1:
                    res.append([i, j])
        return res

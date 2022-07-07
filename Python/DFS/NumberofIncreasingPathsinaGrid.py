# https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        mod = 10**9 + 7
        dirs = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        @cache
        def dfs(i, j):
            return sum((1 + dfs(i + x, j + y)) for x, y in dirs if i + x >= 0 and i + x < m and j + y >= 0 and j + y < n and grid[i][j] > grid[i + x][j + y]) % mod
        return (sum([dfs(i, j) % mod for i in range(m) for j in range(n)]) + m*n) % mod

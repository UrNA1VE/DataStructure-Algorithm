# https://leetcode.com/problems/cyclically-rotating-a-grid/

class Solution:
    def rotateGrid(self, grid, k: int):

        self.m = len(grid)
        self.n = len(grid[0])
        max_time = min(self.m, self.n) // 2
        res = [[0] * self.n for i in range(self.m)]
        for i in range(max_time):
            target = self.check(grid, i)
            target = k % target
            for j in range(target):
                self.rotate(grid, i)

        return grid


    def rotate(self, grid, curr):
        right = self.n - 1 - curr
        down = self.m - 1 - curr
        # left_top = [curr, curr]
        # left_bottom = [self.m - 1 - curr, curr]
        # right_top = [curr, self.n - 1 -curr]
        # right_bottom = [self.m - 1 -curr, self.n - 1 - curr]
        val = grid[curr][curr]
        for j in range(curr, right):
            grid[curr][j] = grid[curr][j + 1]

        for i in range(curr, down):
            grid[i][right] = grid[i + 1][right]

        for j in range(right, curr, -1):
            grid[down][j] = grid[down][j - 1]

        for i in range(down, curr, -1):
            grid[i][curr] = grid[i - 1][curr]

        grid[curr + 1][curr] = val





    def check(self, grid, curr):
        first = (self.m - 1 -curr) - (curr) + 1
        second = (self.n - 1 -curr) - (curr) + 1
        return (first + second) * 2 - 4

# https://leetcode.com/problems/number-of-islands/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        visit = set()
        process = deque()
        rows = len(grid)
        cols = len(grid[0])
        count = 0
        def bfs(i, j):
            process.append((i, j))
            while process:
                x, y = process.popleft()
                dire = [[x + 1, y], [x - 1, y], [x, y + 1], [x, y - 1]]
                for xx, yy in dire:
                    if 0 <= xx < rows and 0 <= yy < cols and grid[xx][yy] == '1' and (xx, yy) not in visit:
                        process.append((xx, yy))
                        visit.add((xx, yy))



        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1' and (i, j) not in visit:
                    visit.add((i, j))
                    bfs(i, j)
                    count += 1

        return count

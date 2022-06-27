# https://leetcode.com/problems/surrounded-regions/

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if not board:
            return None
        rows = len(board)
        cols = len(board[0])
        visited = set()
        def bfs(i, j):
            process = deque()
            process.append((i, j))
            cur_visited = set()
            cur_visited.add((i, j))
            visited.add((i, j))
            flag = 0
            while process:
                x, y = process.popleft()
                directions = [[x - 1, y], [x + 1, y], [x, y - 1], [x, y + 1]]
                for xx, yy in directions:
                    if xx >= rows or xx < 0 or yy < 0 or yy >= cols:
                        flag = 1
                    else:
                        if (xx, yy) not in visited and board[xx][yy] == 'O':
                            visited.add((xx, yy))
                            process.append((xx, yy))
                            cur_visited.add((xx, yy))
            if flag == 1:
                return
            for x, y in cur_visited:
                board[x][y] = 'X'
            return

        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'O' and (i, j) not in visited:
                    bfs(i, j)
        return

        """
        Do not return anything, modify board in-place instead.
        """

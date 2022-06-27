# https://leetcode.com/problems/word-search/

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = set()
        if not word:
            return True
        if not board:
            return False
        rows = len(board)
        cols = len(board[0])
        def dfs(i, j, k):
            if k == len(word):
                return True
            if i < 0 or i >= rows or j < 0 or j >= cols or board[i][j] != word[k] or (i, j) in visited:
                return False
            visited.add((i, j))
            res = dfs(i + 1, j, k + 1) or dfs(i - 1, j, k + 1) or dfs(i, j - 1, k + 1) or dfs(i, j + 1, k + 1)
            visited.remove((i, j))
            return res


        for i in range(rows):
            for j in range(cols):
                if dfs(i, j, 0):
                    return True
        return False

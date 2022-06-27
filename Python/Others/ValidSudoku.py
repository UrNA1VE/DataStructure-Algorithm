# https://leetcode.com/problems/valid-sudoku/

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in range(len(board)):
            ex = set()
            for col in range(len(board)):
                if board[row][col] == '.':
                    continue
                if board[row][col] in ex:
                    return False
                else:
                    ex.add(board[row][col])
        for col in range(len(board)):
            ex = set()
            for row in range(len(board)):
                if board[row][col] == '.':
                    continue
                if board[row][col] in ex:
                    return False
                else:
                    ex.add(board[row][col])
        sub = [0, 3, 6]
        for i in sub:
            for j in sub:
                ex = set()
                for row in range(3):
                    for col in range(3):
                        if board[row + i][col + j] == '.':
                            continue
                        if board[row + i][col + j] in ex:
                            return False
                        else:
                            ex.add(board[row + i][col + j])

        return True

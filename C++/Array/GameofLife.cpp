// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size(), k, x, y, count;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                count = 0;
                for (k = 0; k < 8; k ++) {
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        count += (board[x][y] & 1);
                    }
                }
                if (count == 3 || (count == 2 && board[i][j] == 1)) {
                    board[i][j] |= 2;
                } 
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i][j] >>= 1;
            }
            
        }
 
    }
};

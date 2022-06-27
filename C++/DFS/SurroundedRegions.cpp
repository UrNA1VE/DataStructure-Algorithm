// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int i, int j) {
        if (i <  0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' || visit[i][j]) {
            return;
        }
        board[i][j] = '#';
        visit[i][j] = true;
        
        dfs(board, visit, i, j + 1);
        dfs(board, visit, i, j - 1);
        dfs(board, visit, i + 1, j);
        dfs(board, visit, i - 1, j);
        
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool> (n, false));
        
        for (int j = 0; j < n; j++) {
            dfs(board, visit, 0, j);
            dfs(board, visit, m - 1, j);
        }
        
        for (int i = 1; i < m - 1; i++) {
            dfs(board, visit, i, 0);
            dfs(board, visit, i, n - 1);
        }
        
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};

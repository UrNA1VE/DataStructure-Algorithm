// https://leetcode.com/problems/word-search/

class Solution {
public:
    int m, n, l;
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, string& word, int i, int j, int k) {
        if (k == l) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || visit[i][j] || board[i][j] != word[k]) {
            return false;
        }
        visit[i][j] = true;
        bool res = dfs(board, visit, word, i + 1, j, k + 1) || dfs(board, visit, word, i - 1, j, k + 1) || dfs(board, visit, word, i, j + 1, k + 1) || dfs(board, visit, word, i, j - 1, k + 1);
        visit[i][j] = false;
        return res;        
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        vector<vector<bool>> visit(m, vector<bool> (n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, visit, word, i, j, 0)) return true;
            }
        }
        return false;
        
    }
};

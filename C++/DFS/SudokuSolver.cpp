// https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                char c = board[i][j];
                if (c != '.') {
                    rows[i].insert(c);
                    cols[j].insert(c);
                    int index = 3 * (i / 3) + j / 3;
                    grids[index].insert(c);
                }
            }
        }
        
        dfs(0, board);
        return;
        
        
    }
private:
    vector<unordered_set<char>> rows = vector<unordered_set<char>> (9, unordered_set<char>());
    vector<unordered_set<char>> cols = vector<unordered_set<char>> (9, unordered_set<char>());
    vector<unordered_set<char>> grids = vector<unordered_set<char>> (9, unordered_set<char>());
    
    bool dfs(int index, vector<vector<char>>& board) {
        if (index == 81) return true;
        int i = index / 9, j = index % 9;
        int idx = 3 * (i / 3) + j / 3;
        if (board[i][j] != '.') return dfs(index + 1, board);
        
        for (char x = '1'; x <= '9'; x++) {
            if (rows[i].find(x) == rows[i].cend() && cols[j].find(x) == cols[j].cend() && grids[idx].find(x) == grids[idx].cend()) {
                board[i][j] = x;
                rows[i].insert(x);
                cols[j].insert(x);
                grids[idx].insert(x);
                
                if (dfs(index + 1, board)) return true;
                
                board[i][j] = '.';
                rows[i].erase(x);
                cols[j].erase(x);
                grids[idx].erase(x);
                
                
            }
        }
        return false;

    }
    
};

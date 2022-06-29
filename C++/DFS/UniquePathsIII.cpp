// https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int m, n, target = 0, res = 0;
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit,int i, int j, int count) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || visit[i][j]) {
            return;
        }
        
        if (grid[i][j] == 2) {
            if (count == target) res++;
            return;
        }
        
        visit[i][j] = true;
        
        dfs(grid, visit, i + 1, j, count + 1);
        dfs(grid, visit, i - 1, j, count + 1);
        dfs(grid, visit, i, j + 1, count + 1);
        dfs(grid, visit, i, j - 1, count + 1);
        
        visit[i][j] = false;
        
        return;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool> (n, false));
        int start_i, start_j;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
                else if (grid[i][j] == 0) {
                    target++;
                }
            }
        }
        
        dfs(grid, visit, start_i, start_j, -1);
        return res;
        
    }
};

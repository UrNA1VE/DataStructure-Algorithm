// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int m, n;
    
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(grid, i, j, visited)) {
                    ret += 1;
                }
            }
        }
        
        return ret;
    }
    
    bool dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i >= m || i < 0 || j >= n || j < 0 || visited[i][j] || grid[i][j] == '0') return false;
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
        return true;
    }
};

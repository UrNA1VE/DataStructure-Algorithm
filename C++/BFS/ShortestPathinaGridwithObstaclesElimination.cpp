// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        q.push({0, 0, 0, k});
        int x = 0, y = 0, steps, left;
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            x = curr[0];
            y = curr[1];
            steps = curr[2];
            left = curr[3];
            
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            
            if (x == m - 1 && y == n - 1) {
                return steps;
            }
            
            if (grid[x][y] == 1) {
                if (left > 0) {
                    left--;
                }
                else continue;
            }
            
            if (dp[x][y] != -1 && left <= dp[x][y]) {
                continue;
            }
            else if (left > dp[x][y]) {
                dp[x][y] = left;
            }
            
            q.push({x + 1, y, steps + 1, left});
            q.push({x - 1, y, steps + 1, left});
            q.push({x, y + 1, steps + 1, left});
            q.push({x, y - 1, steps + 1, left});
            
        }
        return -1;
        
    }
};

// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        memset(dp, -1, sizeof(dp));
        
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        dp[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (int k = 0; k < 4; k++) {
                int xx = x + dir[k][0], yy = y + dir[k][1];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && dp[xx][yy] == -1) {
                    dp[xx][yy] = dp[x][y] + (grid[xx][yy] == 1);
                    if (grid[xx][yy] == 1) {
                        q.push_back({xx, yy});
                    }
                    else {
                        q.push_front({xx, yy});
                    }
                }
                
            }
        }
        return dp[m - 1][n - 1];
    }
};

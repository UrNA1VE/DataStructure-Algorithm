// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), countup = 0, countdown = 0;
        if (m == 1 || n < 3) return 0;
        vector<vector<int>> dp1(m, vector<int> (n, 0));
        vector<vector<int>> dp2(m, vector<int> (n, 0));
        for (int j = 0; j < n; j++) {
            if (grid[m - 1][j] == 1) {
                dp1[m - 1][j] = 1;
            }
        }
        
        for (int i = m - 2; i >= 0; i--) {
            dp1[i][0] = grid[i][0];
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1) {
                    if (dp1[i + 1][j] != 0 && dp1[i + 1][j - 1] != 0 && dp1[i + 1][j + 1] != 0) {
                        dp1[i][j] = min(dp1[i + 1][j], min(dp1[i + 1][j + 1], dp1[i + 1][j - 1])) + 1;
                        countup += dp1[i][j] - 1;
                    }
                    else {
                        dp1[i][j] = 1;
                    }
                }
            }
            dp1[i][n - 1] = grid[i][n - 1];
        }
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                dp2[0][j] = 1;
            }
        }
        
        for (int i = 1; i < m; i++) {
            dp2[i][0] = grid[i][0];
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1) {
                    if (dp2[i - 1][j] != 0 && dp2[i - 1][j - 1] != 0 && dp2[i - 1][j + 1] != 0) {
                        dp2[i][j] = min(dp2[i - 1][j], min(dp2[i - 1][j + 1], dp2[i - 1][j - 1])) + 1;
                        countup += dp2[i][j] - 1;
                    }
                    else {
                        dp2[i][j] = 1;
                    }
                }
                    
            }
            dp2[i][n - 1] = grid[i][n - 1];
        }
        return countup+countdown;
    }
};

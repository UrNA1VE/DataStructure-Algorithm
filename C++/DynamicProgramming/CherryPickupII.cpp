// https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, 0)));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int curr = grid[i][j], prev = 0;
                    if (j != k) curr += grid[i][k];
                    
                    if (i != m - 1) {
                        for (int jj = j - 1; jj <= j + 1; jj++) {
                            for (int kk = k - 1; kk <= k + 1; kk++) {
                                if (jj >= 0 && jj < n && kk >= 0 && kk < n) {
                                    prev = max(prev, dp[i + 1][jj][kk]);
                                }
                            }
                        }
                    }
                    curr += prev;
                    dp[i][j][k] = curr;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};

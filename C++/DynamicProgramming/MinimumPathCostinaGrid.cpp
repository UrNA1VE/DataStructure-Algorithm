// https://leetcode.com/problems/minimum-path-cost-in-a-grid/

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        vector<int> predp(n, 0);
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int curr = grid[i][j];
                for (int k = 0; k < n; k++) {
                    dp[k] = min(predp[j] + moveCost[curr][k] + curr, dp[k]);
                }
                
            }
            swap(dp, predp);
            for (int j = 0; j < n; j++) {
                dp[j] = INT_MAX;
            }
        }
        for (int j = 0; j < n; j++) {
                predp[j] += grid[m - 1][j];
            }
        return *min_element(predp.begin(), predp.end());
    }
};

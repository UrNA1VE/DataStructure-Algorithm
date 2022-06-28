// https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        for (int len = 1; len <= n ; len++) {
            for (int start = 1; start <= n - len + 1; start ++) {
                int end = start + len  - 1;
                int best = 0;
                for (int k = start; k <= end; k ++) {
                    best = max(best, dp[start][k - 1] + dp[k + 1][end] + nums[start - 1] * nums[k] * nums[end + 1]);
                }
                dp[start][end] = best;
            }
        }
        return dp[1][n];
    }
};

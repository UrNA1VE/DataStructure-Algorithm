// https://leetcode.com/problems/count-number-of-special-subsequences/

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        long long dp[3] = {0, 0, 0};
        int mod = 1e9+7;
        for (int i: nums) {
            if (i == 0) {
                dp[0] = (dp[0] + dp[0] + 1) % mod;
            }
            else if (i == 1) {
                dp[1] = (dp[0] + dp[1] + dp[1]) % mod;
            }
            else {
                dp[2] = (dp[1] + dp[2] + dp[2]) % mod;
            }
        }
        return dp[2];
        
    }
};

// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int curr = 1, sq = 1;
        while (curr * curr <= n) {
            sq = curr*curr;
            for (int i = sq; i <= n; i++) {
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
            curr++;
        }
        return dp[n];
        
        
        
    }
    
};

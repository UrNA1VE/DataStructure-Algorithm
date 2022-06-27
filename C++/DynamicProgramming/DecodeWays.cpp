// https://leetcode.com/problems/decode-ways/

class Solution {
public:   
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.length(), res1 = 0, res2 = 0;
        int dp[n + 1];
        memset(dp, 0, n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            if (s[i - 1] == '0') {
                if (s[i - 2] > '2' || s[i - 2] == '0') {
                    dp[i] = 0;
                }
                else {
                    dp[i] = dp[i - 2];
                }
            }
            else {
                if (s[i - 2] == '0' || ((s[i - 1] - '0') + 10*(s[i - 2] - '0')) > 26) {
                    dp[i] = dp[i - 1];
                }
                else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
        }
        return dp[n];
        
    }
};

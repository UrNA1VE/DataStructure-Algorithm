// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.size(), nt = t.size(),i, j;
        vector<vector<unsigned long long int>> dp(ns+1, vector<unsigned long long int>(nt+1, 0));
        
        //first row
        dp[0][0] = 1;
        for(i =0; i<=ns; i++){
            dp[i][0] =1;  
        }
        for(i =1; i<=ns; i++){
            for(j=1; j<=nt; j++){
                //exclude i
                dp[i][j] = dp[i-1][j];
                
                
                //include i
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[ns][nt];
    }
};

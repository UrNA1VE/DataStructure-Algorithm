// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1));
        for (int i = 0; i < s1 + 1; i ++){
            dp[i][0] = i;
        }
        for (int j = 0; j < s2 + 1; j ++){
            dp[0][j] = j;
        }
        for (int i = 1; i < s1 + 1; i ++){
            for (int j = 1; j < s2 + 1; j ++){
                int step1 = dp[i - 1][j] + 1;
                int step2 = dp[i][j - 1] + 1;
                int step3 = (word1[i - 1] == word2[j - 1]? dp[i - 1][j - 1]: dp[i - 1][j - 1] + 2);
                dp[i][j] = min(step1, min(step2, step3));
                
            }
        }
        return dp[s1][s2];
        
    }
};

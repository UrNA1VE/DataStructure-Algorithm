// https://leetcode.com/problems/dungeon-game/


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (dungeon[m - 1][n - 1] >= 0){
            dp[m - 1][n - 1] = 1;
        }
        else {
            dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
        }
        
        for (int i = n - 2; i >= 0; i--){
        
            dp[m - 1][i] = compare(dp[m - 1][i + 1], dungeon[m - 1][i]);
        }
        
        for (int i = m - 2; i >= 0; i--){
            dp[i][n - 1] = compare(dp[i + 1][n - 1], dungeon[i][n - 1]);

        }
        
        for (int k = m + n - 4; k >= 0; k--){
            for (int i = 0; i <= m - 2; i ++){
                int j = k - i;
                if(i >= 0 && j >= 0 && i <= m - 2 && j <= n - 2){
                    int way1, way2;
                    way1 = compare(dp[i + 1][j], dungeon[i][j]);
                    way2 = compare(dp[i][j + 1], dungeon[i][j]);
                    dp[i][j] = min(way1, way2);
                }
            }
        }
        return dp[0][0];
    }
private:
    int compare(int dp, int dungeon){
        if (dungeon >= dp){
            return 1;
        }
        else{
            return dp - dungeon;
        }
    }
};

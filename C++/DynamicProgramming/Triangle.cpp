// https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int n = triangle.size();
        vector<int> pre(n, 0);
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i --){
            if (i == n - 1){
                for (int j = 0; j <= i; j ++){
                    dp[j] = triangle[i][j];
                }
            }
            else{
                dp.swap(pre);
                for (int j = 0; j<= i; j ++){
                    dp[j] = triangle[i][j] + min(pre[j], pre[j + 1]);
                }
            }
        }
        return dp[0];
    }
};

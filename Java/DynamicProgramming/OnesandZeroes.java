// https://leetcode.com/problems/ones-and-zeroes/

class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (String s: strs) {
            int count0 = 0, count1 = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') count1++;
                else count0++;
            }
            for (int i = m; i >= count0; i--) {
                for (int j = n; j>= count1; j--) {
                    dp[i][j] = Math.max(dp[i][j], 1 + dp[i - count0][j - count1]);
                }
            }
            
        }
        return dp[m][n];
    }
}

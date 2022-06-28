// https://leetcode.com/problems/palindromic-substrings/

class Solution {
    public int countSubstrings(String s) {
        int ret = 0, n = s.length();
        boolean[][] dp = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j){
                    dp[j][i] = true;
                    ret++;
                }
                else if (s.charAt(i) == s.charAt(j)) {
                    if (j + 1 >= i - 1 || dp[j + 1][i - 1]) {
                        dp[j][i] = true;
                        ret++;
                    }
                }
            }
        }
        return ret;
        
    }
}

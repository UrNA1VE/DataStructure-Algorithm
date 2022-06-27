// Given a string s, return the longest palindromic substring in s.
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

class Solution {
    
    String res = "";
    int length = 0;
    
    public boolean helper(int dp[][], String s, int i, int j) { 
        if (dp[i][j] != -1) {
            return dp[i][j] == 1? true: false;
        } 
        boolean ans;
        if (i == j) {
            dp[i][j] = 1;
            ans = true;
        }
        else if (i > j) {
            return true;
        }
        else {
            ans = (s.charAt(i) == s.charAt(j) & helper(dp, s, i + 1, j - 1));
        }
        if (ans) {
            dp[i][j] = 1;
            if (length < j - i + 1) {
                res = s.substring(i, j + 1);
                length = j - i + 1;
            }
        }
        else {
            dp[i][j] = 0;
        }
        return ans;
        
    }
    
    public String longestPalindrome(String s) {
        int n = s.length();
        int dp[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                helper(dp, s, i, j);
            }
        }
        return res;
        

    }
}

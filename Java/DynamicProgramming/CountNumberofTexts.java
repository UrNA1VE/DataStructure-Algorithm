// https://leetcode.com/problems/count-number-of-texts/

class Solution {
    public int countTexts(String pressedKeys) {
        int n = pressedKeys.length();
        int[] dp = new int[n + 1];
        int mod = (int) (1e9 + 7);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i - 2 >= 0 && pressedKeys.charAt(i - 1) == pressedKeys.charAt(i - 2)) {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
                if (i - 3 >= 0 && pressedKeys.charAt(i - 1) == pressedKeys.charAt(i - 3)) {
                    dp[i] = (dp[i] + dp[i - 3]) % mod;
                    if (pressedKeys.charAt(i - 1) == '7' || pressedKeys.charAt(i - 1) == '9') {
                        if (i - 4 >= 0 && pressedKeys.charAt(i - 1) == pressedKeys.charAt(i - 4)) {
                            dp[i] = (dp[i] + dp[i - 4]) % mod;
                        }
                    }
                }
            }
        }
        return dp[n];
        
    }
}

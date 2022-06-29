// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
    public int countVowelStrings(int n) {
        int[] dp = new int[]{1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    dp[j] += dp[k];
                }
            }
        }
        int ret = 0;
        for (int x: dp) {
            ret += x;
        }
        return ret;
        
    }
}

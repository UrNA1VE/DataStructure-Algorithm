// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        long countF = 1, countS = 1, ret1 = 0, ret2 = 0;
        int n = text.length();
        
        for (int i = 0; i < n; i++) {
            if (text.charAt(i) == pattern.charAt(1)) {
                ret1 += countF;
            }
            if (text.charAt(i) == pattern.charAt(0)) {
                countF += 1;
            }

        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (text.charAt(i) == pattern.charAt(0)) {
                ret2 += countS;
            }
            if (text.charAt(i) == pattern.charAt(1)) {
                countS += 1;
            }

        }
        return Math.max(ret1, ret2);
    }
}

// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

class Solution {
    public int helper(List<List<Integer>> piles, Integer[][] dp, int i, int k) {
        if (k <= 0 || i >= piles.size()) return 0;
        if (dp[i][k] != null) return dp[i][k];
        int curr = 0, ret = helper(piles, dp, i + 1, k);
        for (int j = 0; j < Math.min(k, piles.get(i).size()); j++) {
            curr += piles.get(i).get(j);
            ret = Math.max(ret, curr + helper(piles, dp, i + 1, k - j - 1));
        }
        dp[i][k] = ret;
        return ret;
    }
    
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int n = piles.size();
        Integer[][] dp = new Integer[n][k + 1];
        return helper(piles, dp, 0, k);
    }
}

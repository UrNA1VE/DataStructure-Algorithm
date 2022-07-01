// https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/

class Solution {
public:
    int inf = 200*1e6;
    int dp[200][200] = {};

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(nums, 0, n, k);
        
        
    }
    
    
    int dfs(vector<int>& nums, int i, int n, int k) {
        if (i >= n) return 0;
        if (k < 0) return inf;
        if (dp[i][k] != -1) return dp[i][k];
        int sum = 0, MAX = 0, waste = 0, ans = inf;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            MAX = max(nums[j], MAX);
            waste = MAX*(j - i + 1) - sum;
            ans = min(ans, dfs(nums, j + 1, n, k - 1) + waste);
        }
        dp[i][k] = ans;
        return ans;
    }
};

// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

#define ll long long
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<ll, ll> left, right;
        int n = nums.size(), diff;
        ll res = 0, curr = 0;
        ll prefix[n + 1], suffix[n + 1];
        memset(prefix, 0, sizeof(prefix));
        memset(suffix, 0, sizeof(suffix));
        for (int i = 0; i < n; i++) {
            prefix[i + 1] += prefix[i] + nums[i];
            suffix[n - 1 - i] += suffix[n - i] + nums[n - 1 - i];
        }
        
        for (int i = 0; i < n - 1; i++) {
            right[prefix[i + 1] - suffix[i + 1]]++;
        }
        if (right.count(0)) res = right[0];
        for (int i = 0; i < n; i++) {
            curr = 0;
            diff = k - nums[i];
            if (left.count(diff)) curr += left[diff];
            if (right.count(-diff)) curr += right[-diff];
            res = max(res, curr);
            if (i < n - 1) {
                right[prefix[i + 1] - suffix[i + 1]]--;
                left[prefix[i + 1] - suffix[i + 1]]++;
                if (right[prefix[i + 1] - suffix[i + 1]] == 0) {
                    right.erase(prefix[i + 1] - suffix[i + 1]);
                }
            }
            
        }
        return res;
        
    }
};

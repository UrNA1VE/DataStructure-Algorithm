// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = 1, ret = 0;
        if (n == 1) return ret;
        while (j < n) {
            while (i >= j && j < n) {
                j++;
            }
            if (j >= n) break;
            if (nums[j] - nums[i] == k) {
                i++;
                while (i < n && nums[i] == nums[i - 1]) {
                    i++;
                }
                j++;
                while (j < n && nums[j] == nums[j - 1]) {
                    j++;
                }
                ret++;
                
            }
            else if (nums[j] - nums[i] < k) {
                j++;
            }
            else {
                i++;
            }
        }
        return ret;
        
    }
};

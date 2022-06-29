//  https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> helper;
        int n = nums.size(), res = 0, start = 0, end = 0, curr = 0;
        while (end < n) {
            if (helper.find(nums[end]) != helper.cend()) {
                while (helper.find(nums[end]) != helper.cend()) {
                    curr -= nums[start];
                    helper.erase(nums[start++]);
                }
            }
            curr += nums[end]; 
            helper.insert(nums[end++]);   
            res = max(curr, res);
            
        }
        return res;
        
    }
};

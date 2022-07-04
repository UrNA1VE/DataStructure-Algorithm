// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> ret;
        while (i < n && j < n) {
            while (nums[i] < 0) {
                i++;
            }
            ret.push_back(nums[i++]);
            while (nums[j] > 0) {
                j++;
            } 
            ret.push_back(nums[j++]);
        }
        return ret;
        
    }
};

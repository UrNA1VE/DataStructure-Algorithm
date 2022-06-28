// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1]) 
                return nums[i];
            
        }
        return -1;
    }
};

// https://leetcode.com/problems/sum-of-beauty-in-the-array/

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int left[n], right[n];
        int l = nums[0], r = nums[n - 1];
        for (int i = 1; i < n - 1; i++) {
            left[i] = l;
            right[n - 1 - i] = r;
            l = max(l, nums[i]);
            r = min(r, nums[n - 1 - i]);
        }
        
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > left[i] && nums[i] < right[i]) res += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) res++;
        }
            
        return res;
        
        
    }
};

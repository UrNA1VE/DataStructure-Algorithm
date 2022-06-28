// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int small = 1, large = 1, temp, res = nums[0];
        for (int num: nums) {
            temp = small;
            small = min(num, min(num * small, num * large));
            large = max(num, max(num * temp, num * large));
            res = max(res, large);
        }
        return res;
        
    }
};

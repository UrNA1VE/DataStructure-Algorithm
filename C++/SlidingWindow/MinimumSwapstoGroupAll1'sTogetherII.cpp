// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), count1 = 0, window1 = 0, ret = INT_MAX;
        for (int x: nums) {
            if (x == 1) count1++;
        }
        if (count1 == 0) return 0;
        for (int i = 0; i < count1; i++) {
            if (nums[i] == 1) window1++;
            ret = min(ret, count1 - window1);
        }
        for (int i = 1; i < n; i++) {
            int x = (i + count1 - 1>= n)? i + count1 - 1 - n: i + count1 - 1;
            window1 += (nums[x] == 1)? 1: 0;
            window1 -= (nums[i - 1] == 1)? 1: 0;
            ret = min(ret, count1 - window1);
        }
        return ret;
    }
};

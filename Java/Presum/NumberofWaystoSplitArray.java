// https://leetcode.com/problems/number-of-ways-to-split-array/

class Solution {
    public int waysToSplitArray(int[] nums) {
        int ret = 0;
        long total = 0, left = 0;
        for (int x: nums) {
            total += x;
        }
        for (int i = 0; i < nums.length - 1; i++) {
            left += nums[i];
            total -= nums[i];
            if (left >= total) ret++;
        }
        return ret;
    }
}

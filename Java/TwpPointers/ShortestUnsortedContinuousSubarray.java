// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int n = nums.length;
        int l = 0, r = n - 1, min = 100000, max = -100000;
        while (l < n - 1 && nums[l] <= nums[l + 1]) {
            l++;
        }
        if (l == n - 1) {
            return 0;
        }
        
        while (r > 0 && nums[r] >= nums[r - 1]) {
            r--;
        }
        if (l == 0 && r == n - 1) {
            return n;
        }
        
        for (int i = l; i <= r; i++) {
            min = Math.min(min, nums[i]);
            max = Math.max(max, nums[i]);
        }
        
        while (r < n - 1 && nums[r + 1] < max) {
            r++;
        }
        while (l > 0 && nums[l - 1] > min) {
            l--;
        }
        return r - l + 1;
        
    }
}

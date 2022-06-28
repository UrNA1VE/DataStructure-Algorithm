// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] < 0) return idx + 1;
            nums[idx] = -1 * nums[idx];
            
        }
        return -1;
        
    }
}

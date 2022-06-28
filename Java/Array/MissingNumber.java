// https://leetcode.com/problems/missing-number/

class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        boolean flag = false;
        for (int x: nums) {
            int num = Math.abs(x);
            if (num == n) {
                flag = true;
            }
            else {
                nums[num] = -nums[num];
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i;
            
        }
        for (int i = 0; i < n; i++) {
            if (flag && nums[i] == 0) return i;
            
        }
        
        return n;   
    }
}

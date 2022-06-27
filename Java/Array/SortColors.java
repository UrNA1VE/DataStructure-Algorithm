// https://leetcode.com/problems/sort-colors/

class Solution {
    public void helper(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    public void sortColors(int[] nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) num0++;
            else if (nums[i] == 1) num1++;
            else num2++;
        }
        int n = num0 + num1 + num2;
        int j = num0;
        for (int i = 0; i < num0; i++) {
            if (nums[i] == 0) continue;
            while (j < n && nums[j] != 0) {
                j++;
            }
            helper(nums, i, j);
        }
        j = num1 + num0;
        for (int i = num0; i < num0 + num1; i++) {
            if (nums[i] == 1) continue;
            while (j < n && nums[j] != 1) {
                j++;
            }
            helper(nums, i, j);
        }
        
    }
}

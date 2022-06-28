// https://leetcode.com/problems/rotate-function/

class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length, add = 0, didx = n - 1, aidx = 0;
        int[] arr = new int[n];
        for (int i = 1; i < n; i++) {
            add += nums[i];
            arr[0] += i * nums[i];
        }
        int res = arr[0];
        int delete = 0;
        for (int i = 1; i < n; i++) {
            add -= nums[didx];
            add += nums[aidx];
            arr[i] = arr[i - 1] + add - (n - 1)*nums[didx];
            res = Math.max(res, arr[i]);
            aidx = didx;
            didx--;
        }
       return res; 
        
    }
}

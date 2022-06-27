// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[r] && nums[mid] == nums[l]) {
                l++;
                r--;
            }
            else if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return false;
        
    }
}

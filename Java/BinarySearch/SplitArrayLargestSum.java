// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
    public boolean helper(int[] nums, int m, int mid) {
        int subsum = 0, count = 1;
        for (int x: nums) {
            if (subsum + x > mid) {
                subsum = x;
                count += 1;
            }
            else {
                subsum += x;
            }
        }
        return count <= m;
    }
    
    public int splitArray(int[] nums, int m) {
        int mintarget = 0, maxtarget = 0, ret = 0;
        for (int x: nums) {
            maxtarget += x;
            mintarget = Math.max(mintarget, x);
        }
        
        while (mintarget <= maxtarget) {
            int mid = mintarget + (maxtarget - mintarget)/2;
            if (helper(nums, m, mid)) {
                ret = mid;
                maxtarget = mid - 1;
            }
            else {
                mintarget = mid + 1;
            }
        }
        return ret;
        
    }
}

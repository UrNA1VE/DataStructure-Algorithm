// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
    public boolean helper(int[] candies, long k, int target) {
        long count = 0;
        for (int x: candies) {
            count += x/target;
        }
        if (count >= k) {
            return true;
        }
        return false;
    }
    
    public int maximumCandies(int[] candies, long k) {
        int r = 10000000, l = 1, ret = 0;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (helper(candies, k, mid)) {
                ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ret;
        
        
    }
}

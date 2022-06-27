// link: https://leetcode.com/problems/container-with-most-water/

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int l = 0, r = n - 1, ret = -1;
        while (l < r) {
            ret = Math.max(ret, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ret;
    }
}

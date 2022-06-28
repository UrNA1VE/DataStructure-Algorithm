// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (r > l){
            mid = (l + r) / 2;
            if (nums[mid] > nums[r]){
                l = mid + 1;
            }
            else if (nums[mid] < nums[r]){
                r = mid;
            }
            else {
                r--;
            }
        }
        return nums[l];
        
    }
};

//  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for (int x: nums) {
            if (i < 2 || x != nums[i - 2]) {
                nums[i++] = x;
            }
        }
        return i;
    }
};

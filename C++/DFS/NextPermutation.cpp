// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i, n = i;;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        for (int j = i; j < k; j++, k--) {
            swap(nums[j], nums[k]);
        }
        if (i > 0) {
            k = i - 1;
            for (int j = i; j <= n; j ++) {
                if (nums[j] > nums[k]) {
                    swap(nums[j], nums[k]);
                    break;
                }
            }
        }

    }
};

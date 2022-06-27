// https://leetcode.com/problems/jump-game/submissions/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > maxjump) return false;
            maxjump = max(maxjump, nums[i] + i);
            if (maxjump >= n - 1) return true;
        }
        return false;
    }
};

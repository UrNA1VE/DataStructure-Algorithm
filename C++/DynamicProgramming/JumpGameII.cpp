// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0, cur_reach = 0, res = 1;
        if (nums.size() < 2) return 0;
        reach = nums[0];
        cur_reach = nums[0];
        for (int i = 0; i < nums.size(); i++){
            if (i > cur_reach){
                res ++;
                cur_reach = reach;
            }
            reach = max(reach, i + nums[i]);
        }
    return res;
        
    }
};

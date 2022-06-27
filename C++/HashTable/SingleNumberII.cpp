// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int num: nums){
            table[num]++;
        }
        for (auto& x: table){
            if (x.second == 1){
                return x.first;
            }
        }
        return 0;
    }
};

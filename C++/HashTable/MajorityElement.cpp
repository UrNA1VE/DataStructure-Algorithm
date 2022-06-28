// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int num : nums){
            if(++hash_table[num] > nums.size() / 2){
                return num;
            }
        }
        return 0;
    }
};

// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        int n = nums.size(), k = n / 3;
        vector<int> res;
        for (int num: nums) {
            if (table.find(num) == table.cend()) {
                table[num] = 1;
            }
            else {
                table[num] ++;
            }
        }
        for (auto x: table) {
            if (x.second > k) {
                res.push_back(x.first);
            }
        }
        return res;
        
        
    }
};

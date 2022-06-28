// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table;
        vector<int> res;
        
        for (int num: nums1) {
            if (table.find(num) == table.cend()) table[num] = 1;
            else table[num]++;
        }
        
        for (int num: nums2) {
            if (table.find(num) == table.cend()) continue;
            else {
                if (table[num] == 0) continue;
                else {
                    table[num]--;
                    res.push_back(num);
                }
            }
        }
        return res;
        
    }
};

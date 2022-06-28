// https://leetcode.com/problems/contiguous-array/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int curr = 0, n = nums.size();
        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);
        for (int i = 0; i < n; i++) {
            curr += nums[i] == 0? -1: 1;
            if (m.count(curr) && m[curr].size() == 2) {
                m[curr][1] = i;
            }
            else {
                m[curr].push_back(i);
            }
        }
        int ret = 0;
        for (auto x: m) {
            if (x.second.size() == 2) {
                ret = max(ret, x.second[1] - x.second[0]);
            }
        }
        return ret;
    }
};
        

// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m1, m2, m3, m4;
        int n = nums1.size();
        for (int x: nums1) {
            m1[x]++;
        }
        for (int x: nums3) {
            m3[x]++;
        }
        
        for (int x: nums2) {
            for (auto y: m1) {
                m2[x + y.first] += y.second;
            }
        }
        for (int x: nums4) {
            for (auto y: m3) {
                m4[x + y.first] += y.second;
            }
        }
        
        int ret = 0;
        for (auto x: m2) {
            if (m4.count(-x.first)) {
                ret += x.second * m4[-x.first];
            }
        }
        return ret;
    }
};

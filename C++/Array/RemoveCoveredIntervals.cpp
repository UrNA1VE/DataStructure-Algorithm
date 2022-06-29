// https://leetcode.com/problems/remove-covered-intervals/

bool cmp(vector<int>&a, vector<int>&b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ret = 0, max_b = -1, n = intervals.size();
        for (vector<int>& v: intervals) {
            if (v[1] <= max_b) {
                ret++;
            }
            else {
                max_b = v[1];
            }
        }
        
        return n - ret;
        
    }
};

// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        for (vector<int>& x: flowers) {
            start.push_back(x[0]);
            end.push_back(x[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ret;
        for (int x: persons) {
            int l = upper_bound(start.begin(), start.end(), x) - start.begin();
            int r = lower_bound(end.begin(), end.end(), x) - end.begin();
            ret.push_back(l - r);
        }
        return ret;
        
    }
};

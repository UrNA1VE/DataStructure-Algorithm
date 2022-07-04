// https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution {
public:
    int ret = INT_MAX;
    void helper(vector<int>& cookies, int k, int start, vector<int>& maxs) {
        if (start == cookies.size()) {
            ret = min(ret, *max_element(maxs.begin(), maxs.end()));
            return;
        }
        for (int i = 0; i < k; i++) {
            maxs[i] += cookies[start];
            helper(cookies, k, start + 1, maxs);
            maxs[i] -= cookies[start];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> maxs(k, 0);
        helper(cookies, k, 0, maxs);
        return ret; 
    }
};

// https://leetcode.com/problems/minimum-space-wasted-from-packaging/

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        long res = LONG_MAX, last = packages[packages.size() - 1], sumA = 0;
        for (int a: packages) {
            sumA += a;
        }
        for (auto& B: boxes) {
            sort(B.begin(), B.end());
            if (B[B.size() - 1] < last) continue;
            long i = 0, j = 0, curr = 0;
            for (int b: B) {
                j = upper_bound(packages.begin() + i, packages.end(), b) - packages.begin();
                curr += (j - i) * b;
                i = j;
            }
            res = min(res, curr);
        }
        return (res == LONG_MAX) ? -1: (res - sumA) % (long)(1e9+7);
        
    }
};

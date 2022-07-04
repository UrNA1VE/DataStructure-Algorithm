// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        startPos ++;
        int MX = 2e5 + 2;
        vector<int> presum (MX, 0);
        for (vector<int>& x: fruits) {
            presum[x[0] + 1] = x[1];
        }
        for (int i = 1; i < MX; i++) {
            presum[i] += presum[i - 1];
        }
        int res = 0;
        for (int left = startPos; left > 0 && left >= startPos - k; left--) {
            int right = min(MX - 1, startPos + max(0, k - 2*(startPos - left)));
            res = max(res, presum[right] - presum[left - 1]);
        }
        for (int right = startPos; right < MX && right <= startPos + k; right++) {
            int left = max(1, startPos - max(0, k - 2*(right - startPos)));
            res = max(res, presum[right] - presum[left - 1]);
        }
        return res;
    }
};

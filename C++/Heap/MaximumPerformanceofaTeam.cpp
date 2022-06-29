// https://leetcode.com/problems/maximum-performance-of-a-team/


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> array;
        for (int i = 0; i < n; i ++) {
            array.emplace_back(efficiency[i], speed[i]);
        }
        sort(array.rbegin(), array.rend());

        long sumS = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [e, s]: array) {
            if (pq.size() >= k) {
                sumS -= pq.top();
                pq.pop();
            }
            pq.emplace(s);
            sumS += s;
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
};

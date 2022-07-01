// https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> dp;
        int m = queries.size();
        sort(items.begin(), items.end());
        vector<int> res(m, 0);
        
        int beauty = 0;
        for (auto x: items) {
            beauty = max(beauty, x[1]);
            dp[x[0]] = beauty;
        }
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            if (dp.find(q) != dp.end()) {
                res[i] = dp[q];
            }
            else {
                auto it = dp.lower_bound(queries[i]);
                if (it != dp.begin()) {
                    res[i] = (--it)->second;
                }
            }
            
            
        }
        
        return res;
    }
};

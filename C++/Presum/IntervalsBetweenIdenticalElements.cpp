// https://leetcode.com/problems/intervals-between-identical-elements/

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ret(n, 0);
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        for (auto& x: mp) {
            int m = x.second.size();
            long long curr = 0;
            for (int i = 1; i < m; i++) {
                curr += (long long) i * abs(x.second[i] - x.second[i - 1]);
                ret[x.second[i]] += curr;
            }
        }
        
        for (auto& x: mp) {
            int m = x.second.size();
            long long curr = 0;
            for (int i = m - 2; i >= 0; i--) {
                curr += (long long) (m - 1 - i) * abs(x.second[i + 1] - x.second[i]);
                ret[x.second[i]] += curr;
            }
        }
        return ret;
        
    }
};

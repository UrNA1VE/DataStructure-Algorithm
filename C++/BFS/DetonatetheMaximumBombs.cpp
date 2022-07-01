// https://leetcode.com/problems/detonate-the-maximum-bombs/

#define ll long long
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) {
            int x = bombs[i][0], y = bombs[i][1];
            ll r2 = (ll) bombs[i][2] * bombs[i][2];
            for (int j = 0; j < n; j++) {
                if ((ll) (bombs[j][0] - x) * (bombs[j][0] - x) + (ll) (bombs[j][1] - y) * (bombs[j][1] - y) <= r2) {
                    graph[i].push_back(j);
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            queue<int> q;
            unordered_set<int> s{i};
            q.push(i);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int x: graph[node]) {
                    if (!s.count(x)) {
                        s.insert(x);
                        q.push(x);
                    }
                }
            }
            res = max(res, (int) s.size());
            
        }
        return res;
        
    }
};

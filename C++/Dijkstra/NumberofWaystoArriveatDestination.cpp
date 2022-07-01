// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph (n, vector<pll> ());
        for (auto edge: roads) {
            graph[edge[0]].push_back(pair<ll, ll> {edge[1], edge[2]});
            graph[edge[1]].push_back(pair<ll, ll> {edge[0], edge[2]});
        }
        
        vector<ll> curr(n, LONG_MAX);
        vector<ll> ways(n, 0);
        curr[0] = 0;
        ways[0] = 1;
        priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            // if (x.second == n - 1) continue;
            if (x.first > curr[x.second]) continue;
            for (auto [next, time]: graph[x.second]) {
                if (curr[next] > time + x.first) {
                    curr[next] = x.first + time;
                    ways[next] = ways[x.second];
                    pq.push({curr[next], next});
                }
                else if (curr[next] == time + x.first) {
                    ways[next] = (ways[next] + ways[x.second]) % (int) (1e9+7);
                    
                }
                else {
                    continue;
                }
                
            }
            
        }
        return ways[n - 1];
        
    }
};

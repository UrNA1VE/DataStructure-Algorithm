// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/

#define ipair pair<long long, long long>
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<ipair>> G(n), R(n);
        for (vector<int>& edge: edges) {
            int s = edge[0], e = edge[1], w = edge[2];
            G[s].push_back({e, w});
            R[e].push_back({s, w});
        }
        
        auto helper = [&](int start, vector<vector<ipair>>& graph, vector<long long>& dist) {
            priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
            dist[start] = 0;
            pq.push({0, start});
            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();
                if (d > dist[node]) continue;
                for (auto& x: graph[node]) {
                    if (dist[x.first] > dist[node] + x.second) {
                        dist[x.first] = dist[node] + x.second;
                        pq.push({dist[x.first], x.first}); 
                    }
                }
            }
        };
        
        vector<long long> d1(n, LLONG_MAX), d2(n, LLONG_MAX), r1(n, LLONG_MAX);
        helper(src1, G, d1);
        helper(src2, G, d2);
        helper(dest, R, r1);
        long long ret = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || r1[i] == LLONG_MAX) continue;
            ret = min(ret, d1[i] + d2[i] + r1[i]);
        }
        if (ret == LLONG_MAX) return -1;
        return ret;
        
    }
};

// https://leetcode.com/problems/maximum-path-quality-of-a-graph/

class Solution {
public:
    void dfs(vector<int>& values, vector<vector<pair<int, int>>>& graph, vector<int>& visit, int maxtime, int curtime, int& res, int node, int curvalue) {
        if (curtime > maxtime) return;
        
        if (visit[node] == 0) {
            curvalue += values[node];
        }
        visit[node]++;
        
        if (node == 0) {
            res = max(res, curvalue);
        }
        
        for (auto next: graph[node]) {
            dfs(values, graph, visit, maxtime, curtime + next.second, res, next.first, curvalue);
        }
        
        visit[node]--;
        if (visit[node] == 0) {
            curvalue -= values[node];
        }
        
        return;   
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>> ());
        vector<int> visit(n, 0);
        for (auto edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int res = values[0];
        dfs(values, graph, visit, maxTime, 0, res, 0, 0);
        return res;
    }
};

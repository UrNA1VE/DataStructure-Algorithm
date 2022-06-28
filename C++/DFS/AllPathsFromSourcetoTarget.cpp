// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<vector<int>>& graph, unordered_set<int>& visit, vector<int>& curr, int node, int target) {
        if (visit.count(node)) return;
        curr.push_back(node);
        visit.insert(node);
        if (node == target) {
            res.push_back(curr);
        }
        else {
            for (int num: graph[node]) {
                dfs(graph, visit, curr, num, target);
            }
        }
        curr.pop_back();
        visit.erase(node);
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_set<int> visit;
        vector<int> curr;
        
        dfs(graph, visit, curr, 0, n - 1);
        return res;

    }
};

// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> graph(n);
        vector<int> counts(n, 0);
        for (vector<int>& edge:edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
            counts[edge[0]]++;
            counts[edge[1]]++;
        }
        
        vector<int> leaves;
        vector<int> newleaves;
        for (int i = 0; i < n; i++) {
            if (counts[i] == 1) {
                leaves.push_back(i);
            }
        }
        int remain = n;
        while (remain > 2) {
            while (!leaves.empty()) {
                int leaf = leaves.back();
                int node = *(graph[leaf].begin());
                graph[node].erase(leaf);
                graph[leaf].erase(node);
                counts[node]--;
                counts[leaf]--;
                if (counts[node] == 1) {
                    newleaves.push_back(node);
                }
                leaves.pop_back();
                remain--;
            }
            swap(leaves, newleaves);
            while (!newleaves.empty()) {
                newleaves.pop_back();
            }
        }
        return leaves;
        
    }
};

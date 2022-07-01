// https://leetcode.com/problems/count-nodes-with-the-highest-score/

class Solution {
public:
    
    int dfs(vector<vector<int>>& children, vector<long long>& ans, int n, int i) {
        long long down = 1, Sum = 1;
        for (int child: children[i]) {
            int cnt = dfs(children, ans, n, child);
            down *= cnt;
            Sum += cnt;
        }
        ans[i] = down * max(1ll, n - Sum);
        return i != 0? Sum: count(ans.begin(), ans.end(), *max_element(ans.begin(), ans.end()));
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> children(n, vector<int> ());
        vector<long long> ans(n);
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }
        return dfs(children, ans, n, 0);
        
    }
};

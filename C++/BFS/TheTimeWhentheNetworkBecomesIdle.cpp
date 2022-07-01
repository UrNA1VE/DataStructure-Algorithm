// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), curr;
        vector<int> length(n, -1);
        length[0]= 0;
        vector<vector<int>> graph(n, vector<int> ());
        for (vector<int> &x: edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (int i: graph[curr]) {
                if (length[i] == -1) {
                    q.push(i);
                    length[i] = length[curr] + 1;
                }
            }
            
        }
        int res = 0;
        for(int i = 1; i<n; i++) {
            int extraPayload = (length[i] * 2 - 1)/patience[i]; 
            int lastOut = extraPayload * patience[i]; 
            int lastIn = lastOut + length[i] * 2; 
			
            res = max(res, lastIn);
        }
        return res + 1;
        
        
    }
};

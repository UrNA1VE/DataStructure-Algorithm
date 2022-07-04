// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/

class Solution {
public:
    int maximumInvitations(vector<int>& A) {
        int n = A.size(), case1 = 0, case2 = 0;
        vector<int> m(n, -1);
        vector<vector<int>> r(n);
        for (int i = 0; i < n; i++) {
            r[A[i]].push_back(i);
        }
        
        function<int(int)> dfs = [&](int x) {
            if (m[x] != -1) return m[x];
            int ans = 0;
            for (int v: r[x]) {
                ans = max(ans, dfs(v));
            }
            return m[x] = ans + 1;
        };
        
        for (int i = 0; i < n; i++) {
            if (m[i] != -1) continue;
            if (A[A[i]] == i) {
                m[i] = 0;
                m[A[i]] = 0;
                int a = 0, b = 0;
                for (int x: r[i]) {
                    if (x == A[i]) continue;
                    a = max(a, dfs(x));
                }
                for (int x: r[A[i]]) {
                    if (x == i) continue;
                    b = max(b, dfs(x));
                }
                case1 += a + b + 2;
            }
            
        }
        
        function<tuple<int, int, bool>(int)> dfs2 = [&](int x) ->tuple<int, int, bool> {
            if (m[x] != -1) return {x, m[x], false};
            m[x] = 0;
            auto [entry, depth, cycle] = dfs2(A[x]);
            if (cycle) {
                return {entry, depth, true};
            }
            depth += 1;
            return {entry, depth, x == entry};
        };
        
        for (int i = 0; i < n; i++) {
            if (m[i] != -1) continue;
            auto [entry, depth, cycle] = dfs2(i);
            if (cycle) case2 = max(case2, depth);
        }
        return max(case1, case2);
        
    }
};

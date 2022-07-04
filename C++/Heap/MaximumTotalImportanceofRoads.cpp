// https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        for (vector<int>& r: roads) {
            cnt[r[0]]++;
            cnt[r[1]]++;
        }
        
        priority_queue<int, vector<int>, less<int>> pq(cnt.begin(), cnt.end()); 
        long long ret = 0;
        while (n > 0) {
            ret += (long long) pq.top() * n;
            pq.pop();
            n--;
        }
        return ret;
        
    }
};

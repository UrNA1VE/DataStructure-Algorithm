// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

# define pli pair<long long, int>

bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pli, vector<pli>, greater<pli>> used;
        priority_queue<int, vector<int>, greater<int>> non_used;
        int cnt = 0;
        
        for (vector<int>& i: intervals) {
            int start = i[0], end = i[1];
            while (!used.empty() && used.top().first < start) {
                int group = used.top().second;
                used.pop();
                non_used.push(group);
            }
            if (non_used.empty()) {
                used.push({end, cnt++});
            }
            else {
                used.push({end, non_used.top()});
                non_used.pop();
            }
        }
        return cnt;
    }
};

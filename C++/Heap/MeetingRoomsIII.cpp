// https://leetcode.com/problems/meeting-rooms-iii/

#define pli pair<long long, int>

bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> non_used;
        priority_queue<pli, vector<pli>, greater<pli>> used;
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        sort(meetings.begin(), meetings.end(), compare);
        
        for (int i = 0; i < n; i++) {
            non_used.push(i);
        }
        
        for (vector<int>& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            while (!used.empty() && used.top().first <= start) {
                int room = used.top().second;
                used.pop();
                non_used.push(room);
            }
            
            if (!non_used.empty()) {
                int room = non_used.top();
                non_used.pop();
                cnt[room] += 1;  
                used.push({end, room});
            }
            
            else {
                auto next = used.top();
                used.pop();
                used.push({next.first + (end - start), next.second});
                cnt[next.second] += 1;
            }
        }
        
        int ret = -1, MAX = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > MAX) {
                MAX = cnt[i];
                ret = i;
            }
        }
        return ret;
        
    }
};

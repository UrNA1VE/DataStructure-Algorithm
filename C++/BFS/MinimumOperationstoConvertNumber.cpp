// https://leetcode.com/problems/minimum-operations-to-convert-number/

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visit(1001, false);
        queue<int> q, next_q;
        q.push(start);
        int count = 0, curr, k1, k2, k3;
        
        while (!q.empty()) {
            while (!q.empty()) {
                curr = q.front();
                q.pop();
                vector<int> arr;
                for (int num: nums) {
                    arr.push_back(curr + num);
                    arr.push_back(curr - num);
                    arr.push_back(curr ^ num);
                }
                for (int num: arr) {
                    if (num == goal) return count + 1;
                    if (num < 0 || num > 1000 || visit[num]) continue;
                    visit[num] = true;
                    next_q.push(num);
                }
            }
            swap(q, next_q);
            while (!next_q.empty()) {
                next_q.pop();
            }
            count++;
        }
        return -1;
        
        
    }
};

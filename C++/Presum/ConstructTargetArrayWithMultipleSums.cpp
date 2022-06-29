// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long sumS = 0;
        for (int num: target) {
            pq.push(num);
            sumS += num;
        }
        while (pq.top() != 1) {
            int now = pq.top();
            pq.pop();
            sumS -= now;
            if (sumS < 1 || now <= sumS) return false;
            now %= sumS;
            sumS += now;
            pq.push(now ? now : sumS);
            
        }
        return true;
        
    }
};

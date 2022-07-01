// https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int, vector<int>, less<int>> pq(piles.begin(), piles.end());
        int curr, res = 0;
        for (int i = 0; i < k; i ++) {
            curr = (pq.top() + 1)/ 2;
            pq.pop();
            pq.push(curr);
        }
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
        
    }
};

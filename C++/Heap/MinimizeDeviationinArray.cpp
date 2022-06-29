// https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int smallest = INT_MAX, res = INT_MAX, largest;
        for (const int x: nums) {
            int a = !(x & 1) ? x: x*2;
            pq.push(a);
            smallest = min(smallest, a);
        }
        while (!pq.empty()) {
            largest = pq.top();
            pq.pop();
            res = min(res, largest - smallest);
            if (largest & 1) break;
            pq.push(largest / 2);
            smallest = min(smallest, largest/2);
            
            
        }
        return res;
        
        
        
    }
};

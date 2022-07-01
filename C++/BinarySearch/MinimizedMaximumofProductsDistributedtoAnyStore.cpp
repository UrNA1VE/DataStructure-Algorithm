// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    int helper(vector<int>& q, int k) {
        int res = 0;
        for (int num: q) {
            res += num / k;
            res += (num % k == 0)? 0: 1;
        }
        return res;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end()), mid, curr;
        while (l <= r) {
            mid = (l + r) / 2;
            curr = helper(quantities, mid);
            if (curr > n) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        
        return l;
        
    }
};

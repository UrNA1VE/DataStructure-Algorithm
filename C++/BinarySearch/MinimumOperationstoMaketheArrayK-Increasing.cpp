// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/

class Solution {
public:
    int helper(vector<int>& arr) {
        int n = arr.size(), ret = 1;
        vector<int> dp;
        for (int i = 0; i < n; i++) {  
            int x = arr[i];
            auto it = upper_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) {
                dp.push_back(x);
            }
            else {
                dp[it - dp.begin()] = x;
            }
        }
        return n - dp.size(); 
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ret = 0;
        for (int i = 0; i < k && i < n; i++) {
            vector<int> newArr;
            for (int j = i; j < n; j += k) {
                newArr.push_back(arr[j]);
            }
            ret += helper(newArr);
            
        }
        return ret;
        
    }
};

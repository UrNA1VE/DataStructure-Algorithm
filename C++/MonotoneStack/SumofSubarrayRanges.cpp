// https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    
    long long helper(vector<int>& arr, function<bool (int, int) > cmp) {
        long long res = 0;
        int n = arr.size();
        vector<int> s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || cmp(arr[s.back()], arr[i]))) {
                int j = s.back(), k = s.size() < 2? -1: s[s.size() - 2];
                res += (long long) (j - k) * (i - j) * arr[s.back()];
                s.pop_back();
            }
            s.push_back(i);
        }
        return res;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        return helper(nums, less<int>()) - helper(nums, greater<int>());
        
    }
};

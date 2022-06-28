// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001, take = 0, skip = 0;
        vector<int> arr(n, 0);
        for (int num: nums) {
            arr[num] += num;
        }
        
        for (int i = 0; i < n; i++) {
            int takei = skip + arr[i];
            int skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
        
        
    }
};

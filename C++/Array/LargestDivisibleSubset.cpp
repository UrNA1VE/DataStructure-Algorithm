// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), max_index = 0;
        vector<int> father(n, -1);
        vector<int> counts(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && counts[j] + 1 > counts[i]) {
                    counts[i] = counts[j] + 1;
                    father[i] = j;
                }
            }
            if (counts[max_index] < counts[i]) max_index = i;
        }
        
        vector<int> res;
        while (father[max_index] != -1) {
            res.push_back(nums[max_index]);
            max_index = father[max_index];
        }
        res.push_back(nums[max_index]);
        return res;
        
    }
};

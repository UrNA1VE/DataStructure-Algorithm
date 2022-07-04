// https://leetcode.com/problems/recover-the-original-array/

class Solution {
public:
    vector<int> helper(vector<int>& nums, int k, int n) {
        vector<bool> visit(n, false);
        int left = 0, right = 1;
        vector<int> ret;
        while (right < n) {
            if (visit[left]) {
                left++;
            }
            else if (visit[right]) {
                right++;
            }
            else {
                int dif = nums[right] - nums[left];
                if (dif < 2*k) {
                    right++;
                }
                else if (dif > 2*k) {
                    left++;
                }
                else {
                    visit[left] = true;
                    visit[right] = true;
                    ret.push_back(nums[left] + k);
                    left++;
                    right++;
                }
            }
        }
        return ret;
        
    }
    
    
    
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int k = nums[i] - nums[0];
            if (k == 0 || k&1) continue;
            k /= 2;
            vector<int> ret = helper(nums, k, n);
            if (ret.size() * 2 == n) return ret;
            
        }
        return {};
        
    }
};

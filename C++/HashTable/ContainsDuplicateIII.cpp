// https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> table;
        int n = nums.size(), curr, now, pre;
        if(n == 0 || k <= 0  || t < 0) return false;
        for (int i = 0; i < n; i ++) {
            now = nums[i];
            curr = now / ((long) t + 1);
            if (now < 0) curr--;
            if (table.find(curr) != table.cend()) return true;
            else {
                if (table.find(curr + 1) != table.cend() && abs((long) table[curr + 1] - now) <= t) return true;
                if (table.find(curr - 1) != table.cend() && abs((long) table[curr - 1] - now) <= t) return true;
            }
            if (table.size() >= k) {
                pre = nums[i - k] / ((long) t + 1);
                if (nums[i - k] < 0) pre--;
                table.erase(pre);
            }
            table[curr] = now;
        }
        return false;
        
    }
};

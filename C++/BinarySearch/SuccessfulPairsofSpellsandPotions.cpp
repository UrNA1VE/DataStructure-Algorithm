// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size(), m = spells.size();
        vector<int> ret(m, 0);
        for (int i = 0; i< m; i++) {
            int l = 0, r = n - 1, mid = 0, spell = spells[i], idx = n;
            while (l <= r) {
                mid = l + (r - l)/2;
                long long temp = 0;
                temp = (long long) spell * potions[mid];
                if (temp >= success) {
                    idx = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            ret[i] = n - idx;
        }
        return ret;
    }

};

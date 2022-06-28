// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<unordered_set<int>> table (n, unordered_set<int> ());
        table[0].insert(1);
        int diff;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                diff = stones[i] - stones[j];
                if (table[j].find(diff) == table[j].cend()) continue;
                table[i].insert(diff - 1);
                table[i].insert(diff);
                table[i].insert(diff + 1);
 
            }
        }
        return !table[n - 1].empty();
        
    }
};

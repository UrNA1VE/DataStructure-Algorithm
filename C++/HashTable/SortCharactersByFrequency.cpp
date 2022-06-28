// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        multimap<int, char, greater<int>> ordered_counts;
        string res;
        for (char c: s) {
            counts[c]++;
        }
        
        for (auto [c, n]: counts) {
            ordered_counts.insert(pair<int, char> (n, c));
        }
        
        for (auto [n, c]: ordered_counts) {
            res += string (n, c);
        }
        return res;
    }
};

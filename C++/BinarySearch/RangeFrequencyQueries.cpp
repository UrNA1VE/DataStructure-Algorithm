// https://leetcode.com/problems/range-frequency-queries/

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> table;
    
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            table[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(table[value].begin(), table[value].end(), right) - lower_bound(table[value].begin(), table[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

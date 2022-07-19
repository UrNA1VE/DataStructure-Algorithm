// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> dict;
        int n = values.size();
        
        for (int i = 0; i < n; i++) {
            string num = equations[i][0], den = equations[i][1];
            dict[num][num] = 1.0;
            dict[den][den] = 1.0;
            dict[num][den] = values[i];
            dict[den][num] = 1 / values[i];
        }
        
        for (auto& i: dict) {
            string k1 = i.first;
            for (auto& j: dict[k1]) {
                for (auto& k: dict[k1]) {
                    dict[j.first][k.first] = dict[j.first][k1] * dict[k1][k.first];
                }
            }
        }
        
        vector<double> ret;
        for (auto& query: queries) {
            if (dict.count(query[0]) == 0 || dict[query[0]].count(query[1]) == 0)  ret.push_back(-1.0);
            else ret.push_back(dict[query[0]][query[1]]);
            
        }
        return ret;
        
    }
};

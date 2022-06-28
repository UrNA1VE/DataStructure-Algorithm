// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash_table;
        int n = s.length() - 10;
        vector<string> res;
        if (n < 0){
            return res;
        }
        for (int i = 0; i <= n; i ++){
            string str10 = s.substr(i, 10);
            hash_table[str10]++;
        }
        for (auto i = hash_table.cbegin(); i != hash_table.cend(); i++){
            if (i->second > 1){
                res.push_back(i->first);
            }
            
        }
        return res;
    }
};

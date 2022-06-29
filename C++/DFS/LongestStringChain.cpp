// https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for (const string& word: words) all_words.insert(word);
        int res = 1;
        for (const string& word: words) {
            res = max(res, dfs(word));
        }
        return res;
        
    }
private:
    unordered_map<string, int> table;
    unordered_set<string> all_words;
    int dfs(const string& word){
        if (table.find(word) != table.cend()) {
            return table[word];
        }
        int ans = 1;
        for (int i = 0; i < word.size(); i++){
            string new_word = word.substr(0, i) + word.substr(i + 1);
            if (all_words.find(new_word) != all_words.cend()) {
                ans = max(dfs(new_word) + 1, ans);
            }
            
        }
        table[word] = ans;
        return ans;
        
    }
};

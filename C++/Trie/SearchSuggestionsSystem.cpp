// 

// https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    struct Trie {
        Trie* children[26];
        vector<string> suggests;
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie* root = new Trie();
        for (string& word: products) {
            Trie* p = root;
            for (char c: word) {
                
                if (p->children[c - 'a'] == nullptr) {
                    p->children[c - 'a'] = new Trie();
                }
                p = p->children[c - 'a'];
                if (p->suggests.empty() || p->suggests.size() < 3) {
                    p->suggests.push_back(word);
                }
            }
        }
        int n = searchWord.length();
        vector<vector<string>> ret(n);
        for (int i = 0; i < n; i++) {
            root = root->children[searchWord[i] - 'a'];
            if (root == nullptr) break;
            ret[i] = root->suggests;
        }
        return ret;
    }
};

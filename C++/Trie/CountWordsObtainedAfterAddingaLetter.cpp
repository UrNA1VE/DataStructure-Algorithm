// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

class TrieNode {
public:
    TrieNode* children[26] = {};
    bool word;
    TrieNode() {
        word = false;
    }
    
    void insert(string &s) {
        TrieNode *p = this;
        for (char c: s) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->word = true;
    }
    
    bool find(string &s, bool skip, int p) {
        if (p == s.length()) {
            return skip&&word; 
        }
        int idx = s[p] - 'a';
        return(children[idx] != nullptr ? children[idx]->find(s, skip, p + 1) : false) || (skip ? false : find(s, true, p + 1));
    }
};

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        TrieNode* root = new TrieNode();
        int ret = 0;
        for (string &s : startWords) {
            sort(s.begin(), s.end());
            root->insert(s);
        }
        
        for (string &s: targetWords) {
            sort(s.begin(), s.end());
            ret += root->find(s, false, 0);
        }
        return ret;
        
    }
};

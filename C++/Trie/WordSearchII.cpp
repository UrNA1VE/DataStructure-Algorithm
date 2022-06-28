// https://leetcode.com/problems/word-search-ii/

class TrieNode {
public:
    bool flag = false;
    TrieNode* children[26] = {};
    string* w;
    void insert(string& word) {
        TrieNode* curr = this;
        for (char c: word) {
            if (curr->children[c - 'a'] == nullptr) {
                TrieNode* node = new TrieNode();
                curr->children[c - 'a'] = node;
            }
            curr = curr->children[c - 'a'];
        }
        curr->flag = true;
        curr->w = &word;
        
    }
};

class Solution {
public:
    vector<string> res;
    TrieNode* root = new TrieNode();
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        for (string& word: words) {
            root->insert(word);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j);
            }
        }
        

        return res;
    }
    
    void dfs(vector<vector<char>>& board, TrieNode* curr, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' || curr->children[board[i][j] - 'a'] == nullptr) return;
        TrieNode *node = curr->children[board[i][j] - 'a'];
        if (node->flag) {
            res.push_back(*(node->w));
            node->flag = false;
        }
        char c = board[i][j];
        board[i][j] = '#';
        dfs(board, node, i + 1, j);
        dfs(board, node, i - 1, j);
        dfs(board, node, i, j + 1);
        dfs(board, node, i, j - 1);
        board[i][j] = c;
        
    }
    
};

// https://leetcode.com/problems/palindrome-pairs/

class Solution {
public:
    
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int index = -1;
    }*root;
    
    void insert(const string& word, int index) {
        TrieNode *temp = root;
        for (char i : word) {
            if (!temp->children.count(i)) temp->children[i] = new TrieNode();
            temp = temp->children[i];
        }
        temp->index = index;
    }
    
    int search(const string& word) {
        TrieNode *temp = root;
        for (char i : word) {
            if (!temp->children.count(i)) return -1;
            temp = temp->children[i];
        }
        return temp->index;
    }
    
    bool ispal(const string& word) {
        int n = word.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (word[i] != word[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        root = new TrieNode();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            insert(word, i);     
        }
        set<vector<int>> temp;
        
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int k = word.length();
            for (int j = 0; j <= k; j++) {
                string left = word.substr(0, j), right = word.substr(j);
                int index = search(left);
                if (index != -1 && ispal(right) && index != i) {
                    temp.insert(vector<int> {i, index});
                }
                index = search(right);
                if (index != -1 && ispal(left) && index != i) {
                    temp.insert(vector<int> {index, i});
                }
            }
        }
        vector<vector<int>> res;
        for (auto x: temp) {
            res.push_back(x);
        }
        return res;

        
    }

};

// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode{
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }   
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c: word){
            if (!node->children[c - 'a']){
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
        
    }
private:
    TrieNode* root = new TrieNode();
    bool search(const char* word, TrieNode* node){
        for (int i = 0; word[i] && node; i++){
            if (word[i] != '.'){
                node = node->children[word[i] - 'a'];
            }else{
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++){
                    node = tmp->children[j];
                    if (search(word + i + 1, node)){
                        return true;
                    }
                }
            }
        }
        return node && node->word;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

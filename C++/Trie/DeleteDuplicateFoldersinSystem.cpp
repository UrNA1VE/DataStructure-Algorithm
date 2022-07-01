// https://leetcode.com/problems/delete-duplicate-folders-in-system/

struct Node {
public:
    string name;
    bool del = false;
    map<string, Node*> children;
    Node(string s = ""): name(s) {}
};

class Solution {
public:
    void addpath(Node* node, vector<string>& path) {
        for (auto& s: path) {
            if (!node->children.count(s)) node->children[s] = new Node(s);
            node = node->children[s];
        }
    }
    
    unordered_map<string, Node*> seen;
    string helper(Node* node) {
        string subfolder;
        for (auto& [name, next]: node->children) {
            subfolder += helper(next);
        }
        if (subfolder.size()) {
            if (seen.count(subfolder)) {
                seen[subfolder]->del = true;
                node->del = true;
            }
            else {
                seen[subfolder] = node;
            }
        }
        return "(" + node->name + subfolder + ")";
    }
    
    vector<string> path;
    vector<vector<string>> ret;
    
    void getpath(Node* node) {
        if (node->del) return;
        path.push_back(node->name);
        ret.push_back(path);
        for (auto& [name, next]: node->children) {
            getpath(next);
        } 
        path.pop_back();
    }
    
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for (auto& path: paths) {
            addpath(root, path);
        }
        helper(root);
        for (auto& [name, next]: root->children) getpath(next);
        return ret;
    }
    
};

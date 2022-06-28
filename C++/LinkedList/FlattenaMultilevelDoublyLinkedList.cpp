// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *res = new Node(-1);
    Node *p = res;
    
    void dfs(Node *curr) {
        if (curr == nullptr) {
            return;
        }
        
        Node *nex = new Node(curr->val);
        p->next = nex;
        nex->prev = p;
        p = p->next;
        
        if (curr->child != nullptr) {
            dfs(curr->child);
        }
        
        dfs(curr->next);
        
    }
    
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node *curr = head;
        dfs(curr);
        res->next->prev = nullptr; 
        return res->next;
    }
};

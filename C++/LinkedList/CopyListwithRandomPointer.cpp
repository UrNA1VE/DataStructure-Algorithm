// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> random_map;
        Node* curr = head;
        Node* dummy = new Node(0);
        Node* res = dummy;
        while (curr != NULL){
            Node* temp = new Node(curr->val);
            dummy->next = temp;
            dummy = dummy->next;
            random_map[curr] = dummy;
            curr = curr->next;
        }
        dummy = res->next;
        curr = head;
        while (curr != NULL){
            dummy->random = random_map[curr->random];
            dummy = dummy->next;
            curr = curr->next;
        }
        return res->next;
        
    }
};

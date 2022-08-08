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
        if (!head) return nullptr;
        
        Node* it = head;        
        while (it) {
            Node* duplicate = new Node(it->val);
            duplicate->next = it->next;
            duplicate->random = it->random;
            it->next = duplicate;
            it = duplicate->next;
        }
        
        it = head;
        while (it) {
            Node* duplicate = it->next;
            duplicate->random = duplicate->random ? duplicate->random->next : nullptr;
            it = duplicate->next;
        }
        
        it = head;
        Node* newHead = head->next;
        while (it) {
            Node* duplicate = it->next;
            it->next = duplicate->next;
            it = duplicate->next;
            duplicate->next = it ? it->next : nullptr;
        }
        
        return newHead;
    }
};

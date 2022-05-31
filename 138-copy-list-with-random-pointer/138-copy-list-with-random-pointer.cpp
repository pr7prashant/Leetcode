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
        if (!head) return head;
        
        Node* it = head;
        while (it) {
            Node* temp = new Node(it->val);
            temp->next = it->next;
            temp->random = it->random;
            it->next = temp;
            it = temp->next;
        }
        
        it = head;
        while (it) {
            Node* duplicate = it->next;
            it = duplicate->next;
            duplicate->random = duplicate->random ? duplicate->random->next : nullptr;
        }
        
        it = head;
        Node* newHead = it->next;
        while (it) {
            Node* duplicate = it->next;
            it->next = duplicate->next;
            it = duplicate->next;
            duplicate->next = duplicate->next ? duplicate->next->next : nullptr;
        }
        
        return newHead;
    }
};

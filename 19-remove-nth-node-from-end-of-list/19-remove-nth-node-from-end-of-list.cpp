/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        while (n--) temp = temp->next;
        
        // If nth node is head
        if (!temp) {
            ListNode* del = head;
            head = head->next;
            del->next = nullptr;
            delete del;
            return head;
        }
        
        ListNode* it = head;
        while (temp && temp->next) {
            temp = temp->next;
            it = it->next;
        }
        
        ListNode* del = it->next;
        it->next = del->next;
        del->next = nullptr;
        delete del;
        
        return head;
    }
};

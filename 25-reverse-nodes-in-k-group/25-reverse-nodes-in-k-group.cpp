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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        
        int n = k;
        ListNode* it = head;
        while (n--) {
            if (!it) return head;
            it = it->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* start = head;
        n = k;
        while (head && n--) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }        
        
        start->next = reverseKGroup(head, k);
        
        return prev;
    }
};

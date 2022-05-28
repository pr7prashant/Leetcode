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
    ListNode* reverseList(ListNode* head) {
        // Using Recursion
        if (!head || !head->next) return head;
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return last;
        
        // Without Recursion
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        
        // while (curr) {
            // head = head->next;
            // curr->next = prev;
            // prev = curr;
            // curr = head;
        // }
        
        // return prev;
    }
};

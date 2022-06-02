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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (head) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        
        return prev;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2, bool isFirst) {
        if (!head1) return head2;
        if (!head2) return head1;
        
        ListNode* newHead;
        if (isFirst) {
            newHead = head1;
            newHead->next = merge(head1->next, head2, false);
        } else {
            newHead = head2;
            newHead->next = merge(head1, head2->next, true);
        }
        
        return newHead;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Find mid
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* head2 = slow->next;
        slow->next = nullptr; 
        head2 = reverse(head2);
        
        // Merge first and second half
        head = merge(head, head2, true);
    }
};

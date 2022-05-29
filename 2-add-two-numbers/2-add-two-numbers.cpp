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
    void addNode(ListNode* &head, ListNode* &it, int digit) {
        ListNode* temp = new ListNode(digit);
        if (!head) {
            head = it = temp;
        } else {
            it->next = temp;
            it = it->next;        
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* newHead = nullptr;
        ListNode* it = nullptr;
        while (l1 && l2) {
            int digit = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            addNode(newHead, it, digit);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            int digit = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            addNode(newHead, it, digit);
            l1 = l1->next;
        }
        
        while (l2) {
            int digit = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            addNode(newHead, it, digit);
            l2 = l2->next;
        }
        
        if (carry > 0) addNode(newHead, it, carry);
        
        return newHead;
    }
};

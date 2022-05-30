/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* it1 = headA, *it2 = headB;
        while (it1 != it2) {
            it2 = it2->next;
            it1 = it1->next;
            
            if (!it1 && !it2) return nullptr;
            
            if (!it1) it1 = headB;
            if (!it2) it2 = headA;
        }                
        
        return it1;
    }
};

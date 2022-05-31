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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        
        while (even && even->next) {
            oddHead->next = oddHead->next->next;
            even->next = even->next->next;
            oddHead = oddHead->next;
            even = even->next;
        }
        oddHead->next = evenHead;
        
        return head;
    }
};

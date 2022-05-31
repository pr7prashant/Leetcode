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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* root;
        
        if (l1->val <= l2->val) {
            root = l1;
            root->next = merge(l1->next, l2);
        }
        
        if (l1->val > l2->val) {
            root = l2;
            root->next = merge(l1, l2->next);
        }
        
        return root;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        ListNode* root = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            root = merge(root, lists[i]);
        }
        
        return root;
    }
};

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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        vector<int> nums;
        ListNode* it = head;
        while (it) {
            nums.push_back(it->val);
            it = it->next;
        }
        
        int curr = 0, i = 0, j = nums.size() - 1;
        it = head;
        while (it) {
            if (curr % 2 == 0) {
                it->val = nums[i++];
            } else {
                it->val = nums[j--];
            }
            it = it->next;
            curr++;
        }
    }
};

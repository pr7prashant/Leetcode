/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        list<TreeNode*> ls;
        bool isRev = false;
        ls.push_back(root);
        
        while (!ls.empty()) {
            int s = ls.size();
            vector<int> temp;
            
            while (s--) {
                TreeNode* curr;
                if (isRev) {
                    curr = ls.back();
                    ls.pop_back();
                    temp.push_back(curr->val);
                    if (curr->right) ls.push_front(curr->right);
                    if (curr->left) ls.push_front(curr->left);
                } else {
                    curr = ls.front();
                    ls.pop_front();
                    temp.push_back(curr->val);
                    if (curr->left) ls.push_back(curr->left);
                    if (curr->right) ls.push_back(curr->right);
                }
            }
            
            isRev = !isRev;
            res.push_back(temp);
        }
        
        return res;
    }
};

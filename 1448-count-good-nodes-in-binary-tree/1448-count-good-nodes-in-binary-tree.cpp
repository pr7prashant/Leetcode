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
    int traverse(TreeNode* root, int mx) {
        if (!root) return 0; 
        
        int ans = root->val >= mx ? 1 : 0;
        int l = traverse(root->left, max(mx, root->val));
        int r = traverse(root->right, max(mx, root->val));
        
        return ans + l + r;
    }
    
    int goodNodes(TreeNode* root) {
        return traverse(root, INT_MIN);
    }
};

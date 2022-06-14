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
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        
        return 1 + max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        
        if (abs(l-r) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

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
    int getDepth(TreeNode* root) {
        return root ? 1 + getDepth(root->left) : 0;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int ld = getDepth(root->left);
        int rd = getDepth(root->right);
        int ans = 0;
        if (ld == rd) ans = pow(2, ld) + countNodes(root->right);
        else ans = 1 + countNodes(root->left) + countNodes(root->right);
        
        return ans;
    }
};
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
    TreeNode* solve(TreeNode* root, int val, int depth, int dir) {
        if (!root && depth > 0) return nullptr;
        
        if (depth == 0) {
            TreeNode* node = new TreeNode(val);
            if (dir == 0) node->left = root ? root : nullptr;
            if (dir == 1) node->right = root ? root : nullptr;
            return node;
        }
        root->left = solve(root->left, val, depth-1, 0);
        root->right = solve(root->right, val, depth-1, 1);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root, val, depth-1, 0);
    }
};
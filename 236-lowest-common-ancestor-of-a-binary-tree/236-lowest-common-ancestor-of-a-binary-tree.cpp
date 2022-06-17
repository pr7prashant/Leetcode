/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findNode(TreeNode* root, TreeNode* target) {
        if (!root) return false;
        
        if (root == target) return true;
        
        return findNode(root->left, target) || findNode(root->right, target);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        if (findNode(p, q)) return p;
        if (findNode(q, p)) return q;
             
        TreeNode* ans = root;
        if (findNode(root->left, p) && findNode(root->left, q)) {
           return lowestCommonAncestor(root->left, p, q);
        }
        if (findNode(root->right, p) && findNode(root->right, q)) {
           return lowestCommonAncestor(root->right, p, q);
        }
        
        return ans;
    }
};

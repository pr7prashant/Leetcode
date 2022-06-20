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
    void traverse(TreeNode* root, vector<TreeNode*>& inorder) {
        if (!root) return;
        
        traverse(root->left, inorder);
        inorder.push_back(root);
        traverse(root->right, inorder);
    }
    
    TreeNode* balance(vector<TreeNode*>& inorder, int start, int end) {
        if (start > end) return nullptr;
        
        int curr = (start+end)/2;
        TreeNode* root = inorder[curr];
        root->left = balance(inorder, start, curr - 1);
        root->right = balance(inorder, curr + 1, end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        traverse(root, inorder);
        return balance(inorder, 0, inorder.size() - 1);
    }
};

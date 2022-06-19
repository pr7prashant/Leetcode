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
    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[start]);
        
        int i = start + 1;
        while (i < preorder.size() && preorder[i] < root->val) i++;
        
        root->left = buildTree(preorder, start + 1, i - 1);
        root->right = buildTree(preorder, i, end);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }
};

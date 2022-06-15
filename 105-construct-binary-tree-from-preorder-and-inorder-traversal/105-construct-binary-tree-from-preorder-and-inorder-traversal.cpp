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
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int idx, int i, int j) {
        if (idx == preorder.size() || i > j) return nullptr;
        
        int curr = preorder[idx];
        TreeNode* node = new TreeNode(curr);
        int k = find(inorder.begin(), inorder.end(), curr) - inorder.begin();
        int l = k - i;
        int r = j - k;
        
        node->left = createTree(preorder, inorder, idx + 1, i, k - 1);
        node->right = createTree(preorder, inorder, idx + l + 1, k + 1, j);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};

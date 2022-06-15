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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int curr, int start, int end) {
        if (start > end) return nullptr;
        
        TreeNode* node = new TreeNode(postorder[curr]);
        
        auto it = find(inorder.begin(), inorder.end(), postorder[curr]);
        int idx = it - inorder.begin();
        int sz = end - idx;
        
        node->left = solve(inorder, postorder, curr - sz - 1, start, idx - 1);
        node->right = solve(inorder, postorder, curr - 1, idx + 1, end);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder[0] == -1) return new TreeNode(-1);
        return solve(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
};

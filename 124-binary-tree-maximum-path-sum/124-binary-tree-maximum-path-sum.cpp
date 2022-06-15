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
    int ans = INT_MIN;
    
    int solve(TreeNode* root) {
        if (!root) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int temp = INT_MIN;
        if (root->val > temp) temp = root->val;
        if (root->val + left > temp) temp = root->val + left;
        if (root->val + right > temp) temp = root->val + right;
        if (root->val + left + right > temp) temp = root->val + left + right;
        
        ans = max(ans, temp);
        
        return max({ root->val, root->val + left, root->val + right, 0 });
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);        
        return ans;
    }
};

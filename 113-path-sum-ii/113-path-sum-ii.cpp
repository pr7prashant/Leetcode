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
    vector<vector<int>> res;
    
    void traverse(TreeNode* root, int targetSum, vector<int>& curr) {
        if (!root) return;
        
        curr.push_back(root->val);
        
        if (!root->left && !root->right && targetSum == root->val) res.push_back(curr);
        
        traverse(root->left, targetSum - root->val, curr);
        traverse(root->right, targetSum - root->val, curr);

        curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        traverse(root, targetSum, curr);
        return res;
    }
};

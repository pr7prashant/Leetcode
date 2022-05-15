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
    int max_depth;
    int sum;
    
    void traverse(TreeNode* root, int depth) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            if (depth > max_depth) {
                max_depth = depth;
                sum = root->val;
            } else if (depth == max_depth) {
                sum += root->val;
            }
            return;
        }
        
        traverse(root->left, depth + 1);
        traverse(root->right, depth + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        max_depth = 0;
        sum = 0;
        traverse(root, 0);
        return sum;
    }
};

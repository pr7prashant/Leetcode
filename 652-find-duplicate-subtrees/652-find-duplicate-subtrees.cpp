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
    unordered_map<string,int> mp;
    vector<TreeNode*> ans;
    
    string traverse(TreeNode* root) {
        if (!root) return "";
        
        string l = traverse(root->left);
        string r = traverse(root->right);
        string key = to_string(root->val) + "_" + l + "_" + r;
        
        if (++mp[key] == 2) ans.push_back(root);
        
        return key;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return ans;
    }
};

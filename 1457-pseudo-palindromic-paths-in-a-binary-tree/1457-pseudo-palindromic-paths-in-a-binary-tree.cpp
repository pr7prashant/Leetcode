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
    unordered_map<int,int> mp;
    
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root) return 0;
        
        mp[root->val]++;
        if (!root->left && !root->right) {
            int odd = 0;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->second & 1) odd++;
                if (odd > 1) break;
            }
            mp[root->val]--;
            return odd <= 1 ? 1 : 0;
        }
        
        int l = pseudoPalindromicPaths(root->left);
        int r = pseudoPalindromicPaths(root->right);
        mp[root->val]--;
        
        return l + r;
    }
};

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
    
    int solve(TreeNode* root, int targetSum, long long preSum) {
        if (!root) return 0;
        
        long long sum = preSum + root->val;
        long long ans = mp[sum - targetSum];
        
        mp[sum]++;
        ans += solve(root->left, targetSum, sum) + solve(root->right, targetSum, sum);
        mp[sum]--;
        
        return ans;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;        
        return solve(root, targetSum, 0);        
    }
};

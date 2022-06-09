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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        
        if (root) q.push(root);
        while (!q.empty()) {
            int s = q.size();
            res.push_back(q.back()->val);
            for (int i = 0; i < s; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front && front->left) q.push(front->left);
                if (front && front->right) q.push(front->right);
            }
        }
        
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    
    bool findNode(TreeNode* node1, TreeNode* node2) {
        if (!node1 || !node2) return false;
        if (node1 == node2) return true;
        return findNode(node1->left, node2) || findNode(node1->right, node2);
    }
    
    TreeNode* getLCA(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        if (findNode(node1, node2)) return node1;
        if (findNode(node2, node1)) return node2;
        if (findNode(root->left, node1) && findNode(root->left, node2)) {
            return getLCA(root->left, node1, node2);
        }
        if (findNode(root->right, node1) && findNode(root->right, node2)) {
            return getLCA(root->right, node1, node2);
        }
        return root;
    }
    
    int getDistance(TreeNode* root, TreeNode* target, int d) {
        if (!root) return 0;
        if (root == target) return d;
        int left = getDistance(root->left, target, d + 1);
        int right = getDistance(root->right, target, d + 1);
        return max(left, right);
    }
    
    void traverse(TreeNode* root, TreeNode* target, TreeNode* curr, int k) {
        if (!curr) return;
        
        TreeNode* lca = getLCA(root, target, curr);
        int d1 = getDistance(lca, target, 0);
        int d2 = getDistance(lca, curr, 0);
        if (d1 + d2 == k) ans.push_back(curr->val);
        
        traverse(root, target, curr->left, k);
        traverse(root, target, curr->right, k);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverse(root, target, root, k);        
        return ans;
    }
};

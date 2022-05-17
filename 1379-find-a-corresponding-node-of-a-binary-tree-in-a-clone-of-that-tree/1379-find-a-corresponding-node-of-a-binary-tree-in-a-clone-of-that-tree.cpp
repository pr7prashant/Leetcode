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
    vector<int> path;
    
    bool getPath(TreeNode* root, TreeNode* target) {
        if (!root) return false;
        if (root == target) return true;
        
        path.push_back(-1);
        if (getPath(root->left, target)) return true;
        path.pop_back();
        
        path.push_back(1);
        if (getPath(root->right, target)) return true;
        path.pop_back();
        
        return false;
    }
    
    TreeNode* getClone(TreeNode* root, int i) {
        if (i == path.size()) return root;
        if (path[i] == -1) return getClone(root->left, i+1);
        if (path[i] == 1) return getClone(root->right, i+1);
        return root;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // bool found = getPath(original, target);
        // if (!found) return nullptr;
        // return getClone(cloned, 0);
        
        if (original == nullptr || original == target) return cloned;
        TreeNode* res = getTargetCopy(original->left, cloned->left, target);
        if (res) return res;
        return getTargetCopy(original->right, cloned->right, target);
    }
};

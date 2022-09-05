/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            vector<int> temp;
            while (s--) {
                Node* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                for (Node* n : curr->children) q.push(n); 
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

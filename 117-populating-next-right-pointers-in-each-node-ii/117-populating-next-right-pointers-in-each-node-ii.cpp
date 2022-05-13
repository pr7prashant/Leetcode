/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // vector<vector<Node*>> arr;
    queue<Node*> q;
    
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            // vector<Node*> temp;
            Node* prev = nullptr;
            while (s--) {
                Node* curr = q.front();
                q.pop();
                // temp.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                if (prev) prev->next = curr;
                prev = curr;
            }
            // arr.push_back(temp);
        }
        
        // for (vector<Node*> v : arr) {
        //     for (int i = 1; i < v.size(); i++) {
        //         Node* prev = v[i-1];
        //         Node* curr = v[i];
        //         prev->next = curr;
        //     }
        // }
        
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        vector<int> visited(101, false);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            visited[curr->val] = true;
            
            // cout << curr->val << endl;
            if (mp.find(curr) == mp.end()) mp[curr] = new Node(curr->val);
            
            for (Node* n : curr->neighbors) {
                if (mp.find(n) == mp.end()) mp[n] = new Node(n->val);
                mp[curr]->neighbors.push_back(mp[n]);
                if (!visited[n->val]) {
                    q.push(n);
                    visited[n->val] = true;
                }
            }
        }

        // for (auto it : mp) {
        //     cout << it.first->val << " : ";
        //     for (auto n : it.second->neighbors) {
        //         cout << n->val << ",";
        //     }
        //     cout << endl;
        // }
        
        return mp[node];
    }
};

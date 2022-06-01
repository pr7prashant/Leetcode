// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct comp {
    bool operator()(Node *n1, Node *n2) {
        return n1->freq > n2->freq;
    }
};

class Solution
{
	public:
	void preorder(Node *root, vector<string> &ans, string path) {
		if (!root) return;

		if (!root->left && !root->right) ans.push_back(path);

		preorder(root->left, ans, path + '0');
		preorder(root->right, ans, path + '1');
	}
	    
	vector<string> huffmanCodes(string S,vector<int> f,int N) {
		 // build min heap
		 priority_queue<Node*, vector<Node*>, comp> pq;
		 for (int i = 0; i < N; i++) {
		 	pq.push(new Node(S[i], f[i]));
		 }

		 // create huffman tree from min heap
		 Node *root;
		 while (pq.size() > 1) {
			 Node *left = pq.top();
			 pq.pop();
			 Node *right = pq.top();
			 pq.pop();

			 root = new Node('$', left->freq + right->freq);
			 root->left = left;
			 root->right = right;

			 pq.push(root);
		 }

		 // traverse tree to generate codes
		 vector<string> ans;
		 preorder(root, ans, "");

		 return ans;
	}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
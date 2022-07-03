// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &stk, int src) {
	    visited[src] = true;
	    
	    for (int n : adj[src]) {
	        if (!visited[n]) dfs(adj, visited, stk, n);
	    }

	    stk.push(src);
	}
	
	void dfsTranspose(vector<int> adj[], vector<bool> &visited, int src) {
	    visited[src] = true;
	    
	    for (int n : adj[src]) {
	        if (!visited[n]) dfsTranspose(adj, visited, n);
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // DFS
        stack<int> stk;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(adj, visited, stk, i);
        }
        
        // Transpose Edges
        vector<int> transpose[V];
        for (int i = 0; i < V; i++) {
            for (int n : adj[i]) {
                transpose[n].push_back(i);
            }
        }
        
        // DFS on Transposed Graph
        visited = vector<bool>(V, false);
        int count = 0;
        
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            
            if (!visited[top]) {
                count++;
                dfsTranspose(transpose, visited, top);
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
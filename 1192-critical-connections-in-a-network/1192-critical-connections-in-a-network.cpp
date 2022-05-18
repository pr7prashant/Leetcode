class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    void dfs(vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& ans, int src, int t) { 
        disc[src] = low[src] = t;

        vector<int> adj = graph[src];
        for (int n : adj) {
            if (disc[n] == -1) {
                parent[n] = src;

                dfs(disc, low, parent, ans, n, t + 1);

                low[src] = min(low[src], low[n]);
            } else if (parent[src] != n) { // Check for back edge
                low[src] = min(low[src], disc[n]); // disc[n] instead of low[n] to take only single back edge
            }

            if (low[n] > disc[src]) ans.push_back({src, n});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create Graph
        for (vector<int>& c : connections) {
            int v1 = c[0], v2 = c[1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> parent(n, -1);
        vector<vector<int>> ans;

        dfs(disc, low, parent, ans, 0, 0);
        
        return ans;
    }
};
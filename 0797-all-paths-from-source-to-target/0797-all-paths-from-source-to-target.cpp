class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<vector<int>>& graph, vector<int>& path, int start, int dest) {
        if (start == dest) return ans.push_back(path);
        
        for (int n : graph[start]) {
            path.push_back(n);
            solve(graph, path, n, dest);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = { 0 };
        solve(graph, path, 0, graph.size() - 1);
        return ans;
    }
};
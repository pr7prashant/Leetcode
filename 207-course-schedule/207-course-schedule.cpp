class Solution {
public:
    bool hasCycle(unordered_map<int, vector<int>>& graph, int start, vector<bool>& visited, vector<bool>& path) {
        visited[start] = path[start] = true;
        path[start] = true;
        for (int n : graph[start]) {
            if (!visited[n]) {
                if (hasCycle(graph, n, visited, path)) return true;
            } else if (path[n]) {
                return true;
            }
        }
        path[start] = false;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create Graph
        unordered_map<int, vector<int>> graph;
        for (vector<int>& curr : prerequisites) graph[curr[1]].push_back(curr[0]);
        
        // Check Cycle
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && hasCycle(graph, i, visited, path)) return false;
        }
        
        return true;
    }
};

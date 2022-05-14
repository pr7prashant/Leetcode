class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create Graph
        unordered_map<int, vector<pair<int,int>>> graph;
        for (vector<int>& t : times) {
            graph[t[0]].push_back({ t[1], t[2] });
        }
        
        // Djikstra
        vector<int> cost(n+1, INT_MAX);
        priority_queue<int> pq;
        int ans = 0;
        pq.push(k);
        cost[k] = 0;
        
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            
            for (pair<int,int>& adj : graph[curr]) {
                auto [v,w] = adj;
                if (cost[curr] + w < cost[v]) {
                    cost[v] = cost[curr] + w;
                    pq.push(v);
                }
            }
        }
        
        for (int i = 1; i < cost.size(); i++) ans = max(ans, cost[i]);
        
        return ans == INT_MAX ? -1 : ans;
    }
};

const int MAX = 1e9 + 7;

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    
    int helper(int src, int dst, int k, vector<vector<int>>& dp) {
        if (k < 0) return MAX;
        
        if (src == dst) return 0;
        
        if (dp[src][k] != -1) return dp[src][k];
        
        int ans = MAX;
        for (pair<int,int>& adj : graph[src]) {
            auto [v, p] = adj;
            ans = min(ans, p + helper(v, dst, k-1, dp));
        }
        
        return dp[src][k] = ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create Graph
        for (vector<int> flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];
            graph[u].push_back({v, p});
        }
        
        vector<vector<int>> dp(n+1, vector<int>(k+2, -1));
        
        int ans = helper(src, dst, k+1, dp);
        return ans == MAX ? -1 : ans;
    }
};

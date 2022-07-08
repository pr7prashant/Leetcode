class Solution {
public:
    int MAX = 1e7 + 7;
    
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int curr, int prevColor, vector<vector<vector<int>>>& dp) {
        if (target < 0) return MAX;
        
        if (curr == m) return target == 0 ? 0 : MAX;
        
        if (dp[target][curr][prevColor] != -1) return dp[target][curr][prevColor];
        
        int ans = MAX;
        if (houses[curr] == 0) {
            for (int i = 1; i <= n; i++) {
                int temp = cost[curr][i-1] + solve(houses, cost, m, n, target - (i != prevColor), curr+1, i, dp);
                ans = min(ans, temp);
            }
        } else {
            int temp = solve(houses, cost, m, n, target - (houses[curr] != prevColor), curr+1, houses[curr], dp);
            ans = min(ans, temp);
        }
        
        return dp[target][curr][prevColor] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        int ans = solve(houses, cost, m, n, target, 0, 0, dp);
        return ans < MAX ? ans : -1;
    }
};

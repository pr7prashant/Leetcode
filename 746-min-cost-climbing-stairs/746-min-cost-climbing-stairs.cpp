class Solution {
public:
    int solve(vector<int>& cost, int curr, vector<int>& dp) {
        if (curr >= cost.size()) return 0;
        if (dp[curr] != -1) return dp[curr];
        return dp[curr] = cost[curr] + min(solve(cost, curr + 1, dp), solve(cost, curr + 2, dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};
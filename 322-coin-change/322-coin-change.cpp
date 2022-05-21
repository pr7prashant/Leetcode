class Solution {
public:
    int helper(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        
        if (n == 0) return INT_MAX - 1;
        
        if (dp[n][amount] != -1) return dp[n][amount];
        
        if (coins[n-1] <= amount) {
            return dp[n][amount] = min(1 + helper(coins, amount - coins[n-1], n, dp), helper(coins, amount, n - 1, dp));
        }
        
        return dp[n][amount] =  helper(coins, amount, n - 1, dp);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();        
        
        // Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        
        // int ans = helper(coins, amount, n, dp);
        
        // return  ans >= INT_MAX - 1 ? -1 : ans;
        
        // Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        
        for (int j = 0; j < amount + 1; j++) dp[0][j] = INT_MAX - 1;
        for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i-1] <= j) {
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount] >= INT_MAX - 1 ? -1 : dp[n][amount];
    }
};

class Solution {
public:
    int solve(vector<int>& prices, int k, int i, int shouldBuy, vector<vector<vector<int>>>& dp) {
        if (k == 0 || i == prices.size()) return 0;
        
        if (dp[i][k][shouldBuy] != -1) return dp[i][k][shouldBuy];
        
        int profit = 0;
        if (shouldBuy) {
            int buy = solve(prices, k, i+1, 0, dp) - prices[i];
            int noBuy = solve(prices, k, i+1, 1, dp);
            profit = max(buy, noBuy);
        } else {
            int sell = solve(prices, k-1, i+1, 1, dp) + prices[i];
            int noSell = solve(prices, k, i+1, 0, dp);
            profit = max(sell, noSell);
        }
        
        return dp[i][k][shouldBuy] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(prices, k, 0, 1, dp);
    }
};

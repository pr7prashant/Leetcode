class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
        if (row == triangle.size()) return 0;
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int ans = INT_MAX;
        int res1 = triangle[row][col] + solve(triangle, row + 1, col, dp);
        int res2 = triangle[row][col] + solve(triangle, row + 1, col + 1, dp);
        ans = min({ans, res1, res2});
        
        // cout << "dp[" << row << "]" << "[" << col << "] = " << ans << endl;
        
        return dp[row][col] = ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        return solve(triangle, 0, 0, dp);        
    }
};

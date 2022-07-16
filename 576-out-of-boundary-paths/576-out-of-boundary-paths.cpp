class Solution {
public:
    int MOD = 1e9 + 7;
    
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    int solve(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp) {
        if (startRow < 0 || startRow == m || startColumn < 0 || startColumn == n) return 1;
        
        if (maxMove == 0) return 0;
        
        if (dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        
        int ans = 0;
        for (pair<int,int> move : moves) {
            auto [dx,dy] = move;
            int newX = startRow + dx;
            int newY = startColumn + dy;
            ans = (ans + solve(m, n, maxMove - 1, newX, newY, dp)) % MOD;
        }
        
        return dp[startRow][startColumn][maxMove] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(52, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};

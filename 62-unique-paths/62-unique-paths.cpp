class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1} };

    bool isValid(int m, int n, int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n) return true;
        return false;
    }

    int dfs(int m, int n, int x, int y, vector<vector<int>>& dp) {
        if (x == m - 1 && y == n - 1) return 1;

        if (dp[x][y] != -1) return dp[x][y];

        int ans = 0;
        for (pair<int,int>& move : moves) {
            auto [dx,dy] = move;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(m, n, newX, newY)) {
                ans += dfs(m, n, newX, newY, dp);
            }
        }

        return dp[x][y] = ans;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(m, n, 0, 0, dp);        
    }
};

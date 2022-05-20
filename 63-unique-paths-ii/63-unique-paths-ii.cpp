class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1} };
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x >=0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
        return false;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp) {
        if (x == grid.size() - 1 && y == grid[0].size() - 1) return 1;
        
        if (dp[x][y] != -1) return dp[x][y];
        
        int ans = 0;
        for (pair<int,int>& move : moves) {
            auto [dx,dy] = move;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(grid, newX, newY) && grid[newX][newY] == 0) {
                ans += dfs(grid, newX, newY, dp);
            }
        }
        
        return dp[x][y] = ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dfs(obstacleGrid, 0, 0, dp);
    }
};

class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<int>>& matrix, int x, int y) {
        if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) return true;
        return false;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, vector<vector<int>>& dp) {
        if (dp[x][y] != -1) return dp[x][y];
        
        int ans = 1;
        visited[x][y] = true;
        for (pair<int,int>& move : moves) {
            auto [dx,dy] = move;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(matrix, newX, newY) && !visited[newX][newY] && matrix[newX][newY] > matrix[x][y]) {
                ans = max(ans, 1 + dfs(matrix, visited, newX, newY, dp));
            }
        }
        visited[x][y] = false;
        
        return dp[x][y] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(matrix, visited, i, j, dp));
            }
        }
        
        return ans;
    }
};

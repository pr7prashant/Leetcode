class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
        return false;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        int ans = 1;
        for (pair<int,int> move : moves) {
            auto [dx,dy] = move;
            int newX = x + dx, newY = y + dy;
            if (isValid(grid, newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY]) {
                ans += dfs(grid, visited, newX, newY);
            }
        }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
        return false;
    }
    
    int solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int startX, int startY, int endX, int endY, int empty) {
        if (startX == endX && startY == endY) return empty == 0 ? 1 : 0;
        
        int paths = 0;
        visited[startX][startY] = true;
        for (pair<int,int>& move : moves) {
            auto [dx,dy] = move;
            int newX = startX + dx, newY = startY + dy;
            if (isValid(grid, newX, newY) && grid[newX][newY] != -1 && !visited[newX][newY]) {
                paths += solve(grid, visited, newX, newY, endX, endY, empty - 1);
            }
        }
        visited[startX][startY] = false;
        
        return paths;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int empty = 0, startX, startY, endX, endY;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    empty++;
                } else if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                }
            }
        }
        
        return solve(grid, visited, startX, startY, endX, endY, empty + 1);
    }
};
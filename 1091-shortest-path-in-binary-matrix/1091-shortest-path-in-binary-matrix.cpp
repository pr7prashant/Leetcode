class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1} };
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x >=0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<tuple<int,int,int>> q;
        
        if (grid[0][0] == 0) q.push({ 0, 0, 1 });
        visited[0][0] = true;
        while (!q.empty()) {
            auto [x,y,d] = q.front();
            q.pop();
            
            if (x == grid.size() - 1 && y == grid.size() - 1) return d;
            
            for (pair<int,int>& move : moves) {
                auto [dx,dy] = move;
                int newX = x + dx;
                int newY = y + dy;
                if (isValid(grid, newX, newY) && !visited[newX][newY] && grid[newX][newY] == 0) {
                    visited[newX][newY] = true;
                    q.push({ newX, newY, d + 1 });
                }
            }
        }
        
        return -1;
    }
};

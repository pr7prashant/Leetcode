class Solution {
public:
    vector<pair<int,int>> moves = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
        return false;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(k+1, false)));
        queue<tuple<int,int,int,int>> q;
        q.push({0,0,k,0});
        
        while (!q.empty()) {
            auto [i,j,k_curr,d] = q.front();
            q.pop();
            
            if (i == grid.size() - 1 && j == grid[0].size() - 1) return d;
            
            visited[i][j][k_curr] = true;
            for (pair<int,int>& move : moves) {
                auto [dx, dy] = move;
                int x = i + dx;
                int y = j + dy;
                
                if (isValid(grid, x, y)) {
                    if (grid[x][y] == 1) {
                        if (k_curr > 0 && !visited[x][y][k_curr-1]) {
                            visited[x][y][k_curr-1] = true;
                            q.push({x,y,k_curr-1,d+1});
                        } 
                    } else {
                        if (!visited[x][y][k_curr]) {
                            visited[x][y][k_curr] = true;
                            q.push({x,y,k_curr,d+1});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

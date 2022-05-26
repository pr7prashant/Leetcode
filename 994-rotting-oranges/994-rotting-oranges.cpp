class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x >= 0 && x < grid.size() && y >= 0 & y < grid[0].size()) return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int t = 0, fresh = 0;
        queue<pair<int,int>> q;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i,j});
            }
        }
        
        if (fresh == 0) return 0;
        
        while (!q.empty()) {
            int s = q.size();
            
            if (fresh == 0) return t;
            
            t++;
            while (s--) {
                auto [x,y] = q.front();
                q.pop();

                for (pair<int,int>& move : moves) {
                    auto [dx,dy] = move;
                    int newX = x + dx;
                    int newY = y + dy;

                    if (isValid(grid, newX, newY) && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        fresh--;
                        q.push({newX,newY});     
                    }
                }
            }
        }
        
        return -1;
    }
};

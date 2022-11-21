class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isBoundary(vector<vector<char>>& maze, int x, int y) {
        if (x == 0 || x == maze.size()-1 || y == 0 || y == maze[0].size()-1) return true;
        return false;
    }
    
    bool isValid(vector<vector<char>>& maze, int x, int y) {
        if (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size()) return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        queue<tuple<int,int,int>> q;
        q.push({ entrance[0], entrance[1], 0 });
        
        while (!q.empty()) {
            auto [x,y,d] = q.front();
            q.pop();
            
            if (isBoundary(maze, x, y) && (x != entrance[0] || y != entrance[1])) return d;
            
            for (pair<int,int>& move : moves) {
                int newX = x + move.first;
                int newY = y + move.second;
                if (isValid(maze, newX, newY) && !visited[newX][newY] && maze[newX][newY] == '.') {
                    visited[newX][newY] = true;
                    q.push({ newX, newY, d+1 });
                }
            }
        }
        
        return -1;
    }
};
class Solution {
public:
    int solve(vector<vector<int>>& grid, int x, int y) {
        if (x == grid.size()) return y;
        if (y < 0 || y >= grid[0].size()) return -1;
        
        int next = y + grid[x][y];
        if (next < 0 || next >= grid[0].size() || grid[x][y] != grid[x][next]) return -1;
        
        return solve(grid, x+1, next);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int i = 0; i < grid[0].size(); i++)
           ans.push_back(solve(grid, 0, i));
        return ans;
    }
};
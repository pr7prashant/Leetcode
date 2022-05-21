class Solution {
public:
    vector<pair<int,int>> moves = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    
    bool isValid(vector<vector<int>>& matrix, int x, int y) {
        if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) return true;
        return false;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        queue<tuple<int,int,int>> q;
        q.push({0,0,0});
        
        while (!q.empty()) {
            auto [x,y,d] = q.front();
            q.pop();
            visited[x][y] = true;
            ans.push_back(matrix[x][y]);
            
            auto [dx,dy] = moves[d];
            int newX = x + dx;
            int newY = y + dy;
            
            if (!isValid(matrix, newX, newY) || visited[newX][newY]) {
                d = (d + 1) % 4;
                auto [dx,dy] = moves[d];
                newX = x + dx;
                newY = y + dy;
            }
            
            if (isValid(matrix, newX, newY) && !visited[newX][newY]) q.push({newX,newY,d});
        }
        
        return ans;
    }
};

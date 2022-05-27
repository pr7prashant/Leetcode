class Solution {
public:
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<int>>& mat, int x, int y) {
        if (x >=0 && x < mat.size() && y >= 0 && y < mat[0].size()) return true;
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        queue<tuple<int,int,int>> q;
        
        int oneCount = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) oneCount++;
                if (mat[i][j] == 0) q.push({i,j,1});
            }
        }
        
        if (oneCount == 0) return mat;
        
        while (!q.empty()) {
            auto [x,y,d] = q.front();
            q.pop();
            
            visited[x][y] = true;
            for (pair<int,int> move : moves) {
                auto [dx,dy] = move;
                int newX = x + dx;
                int newY = y + dy;
                
                if (isValid(mat, newX, newY)) {
                    if (mat[newX][newY] == 1 && !visited[newX][newY]) {
                        oneCount--;
                        mat[newX][newY] = d;
                        q.push({newX,newY,d+1});
                        visited[newX][newY] = true;
                    }
                }                
            }
            
            if (oneCount == 0) return mat;
        }
        
        return mat;
    }
};

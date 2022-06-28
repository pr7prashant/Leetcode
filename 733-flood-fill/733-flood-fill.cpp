class Solution {
public:
    bool isValid(vector<vector<int>>& image, int x, int y) {
        if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size()) return true;
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int initColor = image[sr][sc];
        
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            
            visited[curr.first][curr.second] = true;
            image[curr.first][curr.second] = newColor;
            for (pair<int,int> move : moves) {
                int newX = curr.first + move.first;
                int newY = curr.second + move.second;
                
                if (isValid(image, newX, newY) && !visited[newX][newY] && image[newX][newY] == initColor) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        return image;
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int dest = rows * cols;
        vector<bool> visited(dest + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            
            pair<int, int> front = q.front();
            q.pop();
            
            int curr = front.first;
            int moves = front.second;

            if (curr == dest) return moves;
            
            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next <= dest) {
                    int r = rows - ((next - 1) / cols) - 1;
                    int c = (next - 1) % cols;
                    
                    // Reverse column for odd rows
                    c = (rows - r) % 2 == 0 ? cols - c - 1 : c;
                    
                    // Check for snake or ladder
                    next = board[r][c] == -1 ? next : board[r][c];
                    
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push({next, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};

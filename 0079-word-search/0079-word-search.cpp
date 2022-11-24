class Solution {
public:
    vector<pair<int, int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<char>>& board, int r, int c) {
        if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) return true;
        return false;
    }
    
    bool helper(vector<vector<char>>& board, int r, int c, string& word, int start, vector<vector<bool>>& visited) {
        if (start == word.length() - 1 && word[start] == board[r][c]) return true;
        
        if (word[start] != board[r][c]) return false;
        
        visited[r][c] = true;
        for (pair<int,int> move : moves) {
            auto [dx,dy] = move;
            int row = r + dx;
            int col = c + dy;
            if (isValid(board, row, col) && !visited[row][col] && helper(board, row, col, word, start + 1, visited))
                return true;
        }
        visited[r][c] = false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if (helper(board, i, j, word, 0, visited)) return true;
            }
        }        
        
        return false;
    }
};

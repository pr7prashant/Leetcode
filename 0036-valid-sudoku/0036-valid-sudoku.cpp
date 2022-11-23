class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j) {
        for (int r = 0; r < 9; r++) 
            if (r != i && board[r][j] == board[i][j]) return false;
        
        for (int c = 0; c < 9; c++)
            if (c != j && board[i][c] == board[i][j]) return false;
        
        int x = 3 * (i / 3), y = 3 * (j / 3);
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (x+r != i && y+c != j && board[x+r][y+c] == board[i][j]) return false;
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                if (!isValid(board, i, j)) return false;
            }
        }
        return true;
    }
};
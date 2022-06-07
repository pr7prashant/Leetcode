class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, char n) {
        for (int r = 0; r < 9; r++) {
            if (board[r][j] == n) return false;
        }
        
        for (int c = 0; c < 9; c++) {
            if (board[i][c] == n) return false;
        }
        
        int x = 3 * (i / 3), y = 3 * (j / 3);
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[x+r][y+c] == n) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        
        if (j == 9) return solve(board, i + 1, 0);
        
        if (board[i][j] != '.') return solve(board, i, j+1);

        for (int n = 1; n <= 9; n++) {
            if (isValid(board, i, j, '0' + n)) {
                board[i][j] = '0' + n;
                if (solve(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);   
    }
};

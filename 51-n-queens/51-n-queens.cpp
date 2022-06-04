class Solution {
public:
    vector<vector<string>> res;
    
    bool isValid(vector<string>& board, int r, int c) {
        vector<pair<int, int>> moves = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };
        int n = board.size();
        
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q') return false;
        }
        
        for (pair<int, int> m : moves) {
            auto [x,y] = m;
            int newX = r + x;
            int newY = c + y;
            while (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                if (board[newX][newY] == 'Q') return false;
                newX += x;
                newY += y;
            }
        }
        
        return true;
    }
    
    void solve(vector<string>& board, int row) {
        if (row == board.size()) return res.push_back(board);
        
        for (int i = 0; i < board.size(); i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';
                solve(board, row + 1);
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return res;
    }
};

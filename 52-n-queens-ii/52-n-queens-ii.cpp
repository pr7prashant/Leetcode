class Solution {
public:
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
    
    int solve(vector<string>& board, int row) {
        if (row == board.size()) return 1;
        
        int ans = 0;
        for (int i = 0; i < board.size(); i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';
                ans += solve(board, row + 1);
                board[row][i] = '.';
            }
        }
        
        return ans;
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return solve(board, 0);
    }
};

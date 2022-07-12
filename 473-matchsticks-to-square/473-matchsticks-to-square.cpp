class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<int>& square, int side, int curr) {
        if (curr == matchsticks.size()) {
            for (int i = 0; i < 4; i++) {
                if (square[i] != side) return false;
            }
            return true;
        }
        
        if (matchsticks[curr] > side) return false;
        
        for (int i = 0; i < 4; i++) {
            if (matchsticks[curr] <= side - square[i]) {
                int temp = square[i];
                square[i] += matchsticks[curr];
                if (solve(matchsticks, square, side, curr + 1)) return true;
                square[i] = temp;
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        for (int len : matchsticks) total += len;
        if (total % 4 != 0) return false;
        
        // Solve for larger matchsticks first to detect failure early
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> square(4, 0);
        
        return solve(matchsticks, square, total / 4, 0);
    }
};
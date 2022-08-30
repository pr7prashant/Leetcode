class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        
        // Transpose
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i + 1; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

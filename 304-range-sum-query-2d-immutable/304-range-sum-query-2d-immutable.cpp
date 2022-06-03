class NumMatrix {
public:
    vector<vector<int>> presum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        presum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j == 0) presum[i][j] = matrix[i][j];
                else presum[i][j] = matrix[i][j] + presum[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            if (col1 == 0) sum += presum[i][col2];
            else sum += presum[i][col2] - presum[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

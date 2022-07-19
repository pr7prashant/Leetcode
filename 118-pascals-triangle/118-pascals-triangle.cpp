class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat(numRows, vector<int>(numRows, 0));
        
        for (int i = 0; i < numRows; i++) mat[i][0] = 1;
        
        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < numRows; j++) {
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
            }
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> curr;
            for (int j = 0; j < numRows && mat[i][j] != 0; j++) {
                curr.push_back(mat[i][j]);
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};

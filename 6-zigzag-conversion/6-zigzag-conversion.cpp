class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<vector<char>> mat(numRows, vector<char>(s.length(), '#'));
        int x = 0, y = 0, i = 0, dir = 0;
        while (i < s.length()) {
            while (x < numRows && i < s.length()) mat[x++][y] = s[i++];
            dir = 1;
            x = numRows - 2;
            y++;
            while (x >= 0 && i < s.length()) mat[x--][y++] = s[i++];
            dir = 0;
            x = 1;
            y--;
        }
        
        string ans = "";
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] != '#') ans += mat[i][j];
            }
        }
        
        return ans;
    }
};

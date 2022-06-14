class Solution {
public:
    int LCS(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (word1[i-1] == word2[j-1]) {
            return dp[i][j] = 1 + LCS(word1, word2, i-1, j-1, dp);
        }
        
        return dp[i][j] = max(LCS(word1, word2, i-1, j, dp), LCS(word1, word2, i, j-1, dp));
    }
    
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        int lcs = LCS(word1, word2, len1, len2, dp);    
        return (len1 - lcs) + (len2 - lcs);
    }
};

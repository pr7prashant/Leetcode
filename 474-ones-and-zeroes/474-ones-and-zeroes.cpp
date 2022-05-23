class Solution {
public:
    vector<int> canPick(string& s, int m, int n) {
        if (s.length() > m + n) return {0, 0, 0};

        int zeros = 0, ones = 0;
        for (char ch : s) {
            if (ch == '0') zeros++;
            else if (ch == '1') ones++;
            if (zeros > m || ones > n) return {0, 0, 0};
        }
        
        return {1, zeros, ones};
    }
    
    int helper(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if (i == 0) return 0;
        
        if (dp[m][n][i] != -1) return dp[m][n][i];
        
        vector<int> res = canPick(strs[i-1], m, n);
        if (res[0] == 1) {
            return dp[m][n][i] = max(1 + helper(strs, m-res[1], n-res[2], i-1, dp), helper(strs, m, n, i-1, dp));
        }
        
        return dp[m][n][i] = helper(strs, m, n, i-1, dp);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size() + 1, -1)));
        return helper(strs, m, n, strs.size(), dp);
    }
};

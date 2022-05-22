class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            count++;
            if (i + 1 < len && s[i] == s[i+1]) {
                dp[i][i+1] = true;
                count++;
            }
        }
        
        int k = 2;
        while (len - k > 0) {
            for (int i = 0; i < len - k; i++) {
                int j = i + k;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
            k++;
        }
        
        return count;
    }
};

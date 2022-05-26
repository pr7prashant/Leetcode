class Solution {
public:
    int decode(string& s, int i, vector<int>& dp) {
        if (s[i] == '0') return 0;
        if (i == s.length()) return 1;
        
        if (dp[i] != -1) return dp[i];
            
        if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) {
            return dp[i] = decode(s, i+1, dp) + decode(s, i+2, dp);
        }
        
        return dp[i] = decode(s, i+1, dp);
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return decode(s, 0, dp);        
    }
};

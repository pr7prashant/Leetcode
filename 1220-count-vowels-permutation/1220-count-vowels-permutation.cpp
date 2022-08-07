class Solution {
public:
    long long MOD = 1e9 + 7;
    
    long long helper(int n, char ch, vector<vector<int>>& dp) {
        if (n == 0) return 1;
        
        if (dp[n][ch - 'a'] != -1) return dp[n][ch - 'a'];
        
        long long ans = 0;
        if (ch == 'a') ans += helper(n-1, 'e', dp);
        else if (ch == 'e') ans += helper(n-1, 'a', dp) + helper(n-1, 'i', dp);
        else if (ch == 'i') ans += helper(n-1, 'a', dp) + helper(n-1, 'e', dp) + helper(n-1, 'o', dp) + helper(n-1, 'u', dp);
        else if (ch == 'o') ans += helper(n-1, 'i', dp) + helper(n-1, 'u', dp);
        else if (ch == 'u') ans += helper(n-1, 'a', dp);
        
        return dp[n][ch - 'a'] = ans % MOD;
    }
    
    int countVowelPermutation(int n) {
        vector<char> arr = { 'a', 'e', 'i', 'o', 'u' };
        vector<vector<int>> dp(n+1, vector<int>(26, -1));
        long long ans = 0;
        for (char ch : arr) ans += helper(n-1, ch, dp);
        return ans % MOD;
    }
};

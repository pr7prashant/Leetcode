class Solution {
public:
    long long MOD = 1e9 + 7;
    unordered_map<string,long long> dp;
    
    long long helper(int n, char ch) {
        if (n == 0) return 1;
        
        string key = to_string(n) + "_" + ch;
        if (dp.count(key)) return dp[key];
        
        long long ans = 0;
        if (ch == 'a') ans += helper(n-1, 'e');
        else if (ch == 'e') ans += helper(n-1, 'a') + helper(n-1, 'i');
        else if (ch == 'i') ans += helper(n-1, 'a') + helper(n-1, 'e') + helper(n-1, 'o') + helper(n-1, 'u');
        else if (ch == 'o') ans += helper(n-1, 'i') + helper(n-1, 'u');
        else if (ch == 'u') ans += helper(n-1, 'a');
        
        return dp[key] = ans % MOD;
    }
    
    int countVowelPermutation(int n) {
        vector<char> arr = { 'a', 'e', 'i', 'o', 'u' };
        long long ans = 0;
        for (char ch : arr) ans += helper(n-1, ch);
        return ans % MOD;
    }
};

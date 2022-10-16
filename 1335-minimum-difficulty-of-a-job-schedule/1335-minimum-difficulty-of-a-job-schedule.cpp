class Solution {
public:
    int MOD = 1e9+7;
    
    int solve(vector<int>& jd, int d, int start, vector<vector<int>>& dp) {
        if (d < 0) return MOD;
        
        if (start == jd.size()) return d == 0 ? 0 : MOD;
        
        if (dp[start][d] != -1) return dp[start][d];
        
        int ans = INT_MAX, curr_max = jd[start];
        for (int i = start; i < jd.size(); i++) {
            curr_max = max(curr_max, jd[i]);
            ans = min(ans, curr_max + solve(jd, d-1, i+1, dp));
        }
        
        return dp[start][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d+1, -1));
        return solve(jobDifficulty, d, 0, dp);
    }
};
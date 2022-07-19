class Solution {
public:
    int solve(vector<int>& nums, int start, int prev, vector<vector<int>>& dp) {
        if (start <= 0) return 0;
        
        if (dp[start][prev] != -1) return dp[start][prev];
        
        if (start < prev - 1) {
            return dp[start][prev] = max(nums[start-1] + solve(nums, start-2, start, dp), solve(nums, start-1, prev, dp));
        }
        
        return dp[start][prev] = solve(nums, start - 1, prev, dp);
    }
    
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(102, vector<int>(102, -1));
        return solve(nums, nums.size(), 101, dp);
    }
};

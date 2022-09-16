class Solution {
public:
    int helper(vector<int>& nums, vector<int>& multipliers, int i, int start, vector<vector<int>>& dp) {
        if (i == multipliers.size()) return 0;
        
        if (dp[i][start] != INT_MIN) return dp[i][start];
        
        int pickLeft = nums[start] * multipliers[i] + helper(nums, multipliers, i+1, start+1, dp);
        int pickRight = nums[nums.size()-(i-start)-1] * multipliers[i] + helper(nums, multipliers, i+1, start, dp);
        
        return dp[i][start] = max(pickLeft, pickRight);
    }

    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size()+1, vector<int>(multipliers.size(), INT_MIN));
        return helper(nums, multipliers, 0, 0, dp);
    }
};

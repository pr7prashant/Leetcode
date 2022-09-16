class Solution {
public:
    int helper(vector<int>& nums, vector<int>& multipliers, int i, int start, vector<vector<int>>& dp) {
        if (i == multipliers.size()) return 0;
        
        if (dp[i][start] != INT_MIN) return dp[i][start];
        
        int pickLeft = nums[start] * multipliers[i] + helper(nums, multipliers, i+1, start+1, dp);
        int pickRight = nums[nums.size()+start-i-1] * multipliers[i] + helper(nums, multipliers, i+1, start, dp);
        
        return dp[i][start] = max(pickLeft, pickRight);
    }

    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // vector<vector<int>> dp(multipliers.size()+1, vector<int>(nums.size()+1, INT_MIN));
        vector<vector<int>> dp(1000, vector<int>(1000, INT_MIN));
        return helper(nums, multipliers, 0, 0, dp);
    }
};

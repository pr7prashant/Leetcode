class Solution {
public:
    int solve(vector<int>& nums, int prev, int i, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        
        if (dp[prev][i] != -1) return dp[prev][i];
        
        if (nums[i] > nums[prev]) {
            return dp[prev][i] = max(1 + solve(nums, i, i+1, dp), solve(nums, prev, i+1, dp));
        }
        
        return dp[prev][i] = solve(nums, prev, i+1, dp);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);       
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, 1, dp);
    }
};

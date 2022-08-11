class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int oneStepBack = 0, twoStepBack = 0, ans = 0;
        for (int i = start; i <= end; i++) {
            ans = max(oneStepBack, twoStepBack + nums[i]);
            twoStepBack = oneStepBack;
            oneStepBack = ans;
        }
        return ans;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
};

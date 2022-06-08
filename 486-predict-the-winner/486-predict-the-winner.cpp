class Solution {
public:
    bool solve(vector<int>& nums, int turn, int s1, int s2, int i, int j) {
        if (i > j) {
            if (turn == 1) {
                return s1 >= s2;
            } else {
                return s2 > s1;
            }
        }
        
        if (turn == 1) {
           return !solve(nums, 2, s1 + nums[i], s2, i+1, j) || !solve(nums, 2, s1 + nums[j], s2, i, j-1);
        }
        
        return !solve(nums, 1, s1, s2 + nums[i], i+1, j) || !solve(nums, 1, s1, s2 + nums[j], i, j-1);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 1, 0, 0, 0, nums.size() - 1);
    }
};

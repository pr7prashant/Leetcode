class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& nums, int start) {
        if (start == nums.size()) return res.push_back(nums);
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            helper(nums, start+1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
};

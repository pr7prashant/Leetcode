class Solution {
public:
    vector<vector<int>> ans;
        
    void helper(vector<int>& nums, int start) {
        if (start == nums.size()) return ans.push_back(nums);
        
        unordered_map<int, bool> used;
        for (int i = start; i < nums.size(); i++) {
            if (used[nums[i]]) continue;
            used[nums[i]] = true;
            swap(nums[i], nums[start]);
            helper(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ans;
    }
};

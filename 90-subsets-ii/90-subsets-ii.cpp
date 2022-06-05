class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& nums, vector<int>& curr, int start) {
        if (start == nums.size()) return res.push_back(curr);
        
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1]) continue;    
            curr.push_back(nums[i]);
            helper(nums, curr, i + 1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        helper(nums, curr, 0);
        return res;
    }
};

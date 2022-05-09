class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for (int k = 0; k < nums.size() - 2; k++) {
            if (k > 0 && nums[k] == nums[k-1]) continue;
            
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    i++;
                } else if (sum > 0) {
                    j--;
                } else {
                    ans.push_back({ nums[k], nums[i], nums[j] });
                    i++; j--;
                    while(i < nums.size() && nums[i] == nums[i-1]) i++;
                    while(j >= 0 && nums[j] == nums[j+1]) j--;
                }
            }
        }
        
        return ans;
    }
};

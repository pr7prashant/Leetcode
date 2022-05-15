class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ans;
        
        for (int k = start; k <= nums.size() - 3; k++) {
            if (k > start && nums[k] == nums[k-1]) continue;
            
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                long long sum = (long long)nums[k] + (long long)nums[i] + (long long)nums[j];
                
                if (sum == target) {
                    ans.push_back({ nums[k], nums[i], nums[j] });
                    int temp = nums[i];
                    while (i < nums.size() && nums[i] == temp) i++;
                    temp = nums[j];
                    while (j >= start && nums[j] == temp) j--;
                } else if (sum < target) {
                    i++;    
                } else if (sum > target) {
                    j--;
                }
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        if (nums.size() < 4) return ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            vector<vector<int>> temp = threeSum(nums, i+1, target - nums[i]);

            for (int j = 0; j < temp.size(); j++) {
                ans.push_back({ nums[i], temp[j][0], temp[j][1], temp[j][2] });
            }
        }
        
        return ans;
    }
};

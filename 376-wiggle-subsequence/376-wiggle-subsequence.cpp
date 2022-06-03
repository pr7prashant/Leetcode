class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i-1]) i++;
        if (i == nums.size()) return 1;
        
        int ans = 2;
        bool inc = nums[i] > nums[i-1];
        while (i < nums.size()) {
            if (inc) {
                while (i < nums.size() && nums[i] >= nums[i-1]) i++; 
            } else {
                while (i < nums.size() && nums[i] <= nums[i-1]) i++;
            }
            
            if (i < nums.size()) ans++;
            inc = !inc;
        }
        
        return ans;
    }
};

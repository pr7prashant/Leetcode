class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0, i = 1;
        
        while (i < nums.size()) {
            if (nums[i] < nums[i-1]) {
                count++;
                if (i-2 < 0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
            if (count > 1) return false;
            i++;
        }
        
        return true;
    }
};

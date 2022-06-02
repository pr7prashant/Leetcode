class Solution {
public:
    int getSum(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        return sum;
    }
    
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (k > 0 && i < nums.size() && nums[i] < 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        
        if (k % 2 == 0) return getSum(nums);
        
        vector<int>::iterator m = min_element(nums.begin(), nums.end());
        *m = -1 * (*m);
        
        return getSum(nums);
    }
};

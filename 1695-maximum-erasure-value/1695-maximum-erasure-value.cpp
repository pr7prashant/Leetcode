class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,bool> used;
        int i = 0, j = 0, ans = 0, sum = 0;
        while (j < nums.size()) {
            if (!used[nums[j]]) {
                sum += nums[j];
                ans = max(ans, sum);
                used[nums[j]] = true;
                j++;
            } else {
                while (used[nums[j]]) {
                    sum -= nums[i];
                    used[nums[i]] = false;
                    i++; 
                }
            }
        }
        
        return ans;
    }
};

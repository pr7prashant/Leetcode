class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> presum;
        
        int ans = INT_MAX;
        presum[0] = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            presum[sum] = i+1;
            if (sum == x) ans = min(ans, i+1);
        }
        
        sum = 0;
        for (int j = nums.size() - 1; j >= 0 && sum <= x; j--) {
            sum += nums[j];
            int target = x - sum;
            if (presum.find(target) != presum.end() && presum[target] - 1 < j) {
                int len = presum[target] + nums.size() - j;
                ans = min(ans, len);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

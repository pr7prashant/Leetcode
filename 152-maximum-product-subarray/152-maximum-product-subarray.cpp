class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1, ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            ans = max({ans, prefix, suffix});
            prefix = prefix == 0 ? 1 : prefix;
            suffix = suffix == 0 ? 1 : suffix;
        }
        return ans;
    }
};

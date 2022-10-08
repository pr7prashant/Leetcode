class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1e5 + 7;
        for (int k = 0; k < nums.size() - 2; k++) {
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum == target) return sum;
                ans = abs(sum - target) < abs(ans - target) ? sum : ans;
                if (sum < target) i++;
                else j--;
            }
        }
        return ans;
    }
};

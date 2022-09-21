class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for (int n : nums) if (n % 2 == 0) sum += n;
        
        for (vector<int>& q : queries) {
            int v = q[0], i = q[1];
            if (nums[i] % 2 == 0) sum -= nums[i];
            nums[i] += v;
            if (nums[i] % 2 == 0) sum += nums[i];
            ans.push_back(sum);
        }
        
        return ans;
    }
};
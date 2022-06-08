class Solution {
public:
    bool solve(vector<int>& nums, int subsetSum[], bool visited[], int k, int target, int start, int bucket) {
        if (k == 1) return true;
        if (start == nums.size()) return false;
        if (subsetSum[bucket] == target) return solve(nums, subsetSum, visited, k-1, target, 0, bucket + 1);
        
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                int temp = subsetSum[bucket] + nums[i];
                if (temp > target) continue;
                visited[i] = true;
                subsetSum[bucket] += nums[i];
                if (solve(nums, subsetSum, visited, k, target, i+1, bucket)) return true;
                subsetSum[bucket] -= nums[i];
                visited[i] = false;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) sum += n;
        
        if (sum % k != 0) return false;
        
        int s = nums.size();
        bool visited[s];
        int subsetSum[k];
        for (int i = 0; i < k; i++) subsetSum[i] = 0;
        for (int i = 0; i < s; i++) visited[i] = false;
        // vector<bool> visited(nums.size(), false);
        // vector<int> subsetSum(k, 0);
        
        return solve(nums, subsetSum, visited, k, sum/k, 0, 0);
    }
};

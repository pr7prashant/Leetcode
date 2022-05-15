class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        
        // Map O(n) Time - O(n) Space
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) mp[nums[i]]++;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (k == 0) {
                if (it->second > 1) ans++;
            } else if (mp.find(it->first + k) != mp.end()) {
                ans++;
            }
        }
        
        // Sliding Window O(nlogn) Time - O(1) Space
        // sort(nums.begin(), nums.end());
        
        // int i = 0, j = 1;
        // while (i < len && j < len) {
        //     if (nums[j] - nums[i] == k) {
        //         if (i == j) j++;
        //         else {
        //             ans++;
        //             int temp = nums[j];
        //             while (j < len && nums[j] == temp) j++;
        //         }
        //     } else if (nums[j] - nums[i] < k) {
        //         int temp = nums[j];
        //         while (j < len && nums[j] == temp) j++;
        //     } else {
        //         int temp = nums[i];
        //         while (i < len && nums[i] == temp) i++;
        //     }
        // }
        
        return ans;
    }
};

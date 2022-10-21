class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (mp[nums[j]]++ > 0) return true;
            if (j - i == k) mp[nums[i++]]--;
            j++;
        }
        return false;
    }
};
class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) ans = mid;
            
            if (nums[mid] >= target) end = mid - 1;
            else start = mid + 1;
        }
        return ans;
    }
    
    int findLast(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) ans = mid;
            
            if (nums[mid] <= target) start = mid + 1;
            else end = mid - 1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);        
        int last = findLast(nums, target);       
        vector<int> res = { first, last };
        return res;
    }
};

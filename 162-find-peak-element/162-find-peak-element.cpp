class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        nums.insert(nums.begin(), INT_MIN);
        nums.insert(nums.end(), INT_MIN);
        int start = 1, end = nums.size() - 2;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid - 1;
            
            if (nums[mid] < nums[mid-1]) end = mid - 1;
            else start = mid + 1;
        }
        
        return -1;
    }
};

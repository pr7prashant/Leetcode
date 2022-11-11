class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 1;
        int pos = 0;
        int curr = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != curr) {
                nums[pos+1] = nums[i];
                curr = nums[pos + 1];
                count++;
                pos++;
            }
        }
        return count;
    }
};
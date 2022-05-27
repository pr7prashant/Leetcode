class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        list<int> ls;
        
        int i = 0, j = 0;
        while (j < nums.size()) {
            while(!ls.empty() && nums[j] >= nums[ls.back()]) ls.pop_back();
            ls.push_back(j);
            
            if (j - i + 1 == k) {
                while (ls.front() < i) ls.pop_front();                
                res.push_back(nums[ls.front()]);
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};

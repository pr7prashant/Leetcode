class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(size(nums));
        dp[0] = nums[0];
        deque<int> q{ 0 };
        for(int i = 1; i < size(nums); i++) {
            // can't reach current index from index stored in q     
            if(q.front() < i - k) q.pop_front();
            // update max score for current index
            dp[i] = nums[i] + dp[q.front()];          
            // pop indices which won't be ever chosen in the future
            while(!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            // insert current index
            q.push_back(i);                              
        }
        return dp.back();
    }
};

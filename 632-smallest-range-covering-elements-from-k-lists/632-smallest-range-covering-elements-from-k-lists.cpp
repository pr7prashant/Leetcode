class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        
        int mn = INT_MAX, mx = INT_MIN, range = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][0] < mn) mn = nums[i][0];
            if (nums[i][0] > mx) mx = nums[i][0];
            pq.push({nums[i][0], i, 0});
        }
        range = mx - mn + 1;
        res = {mn, mx};
        
        while (!pq.empty()) {
            auto [n, arr, i] = pq.top();
            pq.pop();
            
            if (i + 1 >= nums[arr].size()) break;
            
            pq.push({nums[arr][i+1], arr, i+1});
            mx = max(mx, nums[arr][i+1]);
            mn = get<0>(pq.top());
            
            if (mx - mn + 1 < range) {
                range = mx - mn + 1;
                res = {mn, mx};
            }
        }
        
        return res;
    }
};

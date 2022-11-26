class Solution {
public:
    int getNext(vector<tuple<int, int, int>>& arr, int curr) {
        auto [s1, e1, p1] = arr[curr];
        
        for (int i = curr + 1; i < arr.size(); i++) {
            auto [s2, e2, p2] = arr[i];
            
            if (s2 >= e1) return i;
        }
        
        return -1;
    }
    
    int helper(vector<tuple<int, int, int>>& arr, int i, vector<int>& dp) {
        if (i == arr.size()) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        auto [start, end, profit] = arr[i];
        
        int inc = profit;
        int next = getNext(arr, i);
        if (next != -1) {
            inc += helper(arr, next, dp);
        }
        
        int exc = helper(arr, i+1, dp);
        
        return dp[i] = max(inc, exc);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size();
        
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < len; i++) {
            arr.push_back({ startTime[i], endTime[i], profit[i] });
        }
        sort(arr.begin(), arr.end());
        
        vector<int> dp(len + 1, -1);
        
        return helper(arr, 0, dp);
    }
};

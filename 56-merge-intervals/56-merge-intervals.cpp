class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int it = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > ans[it][1]) {
                ans.push_back(intervals[i]);
                it++;
            } else if (intervals[i][0] <= ans[it][1]) {
                ans[it][1] = max(ans[it][1], intervals[i][1]);                
            }  
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }
        
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval = { min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1]) };
            i++;
        }
        
        ans.push_back(newInterval);
        
        while (i < intervals.size() ) {
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};

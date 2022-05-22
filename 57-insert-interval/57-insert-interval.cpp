class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool found = false;
        
        for (vector<int>& interval : intervals) {
            if (
                !found && 
                (
                    newInterval[0] >= interval[0] && newInterval[0] <= interval[1] ||
                    newInterval[1] >= interval[0] && newInterval[1] <= interval[1] ||
                    newInterval[0] <= interval[0] && newInterval[1] >= interval[1]
                )
            ) {
                ans.push_back({ min(interval[0], newInterval[0]), max(interval[1], newInterval[1]) });
                found = true;
            } else if (!found && newInterval[1] < interval[0]) {
                ans.push_back(newInterval);
                ans.push_back(interval);
                found = true;
            } else if (ans.size() > 0 && interval[0] <= ans.back()[1]) {
                vector<int> temp = ans.back();
                ans.pop_back();
                ans.push_back({ min(interval[0], temp[0]), max(interval[1], temp[1]) });
            } else {
                ans.push_back(interval);
            }
        }
        
        if (!found) ans.push_back(newInterval);
        
        return ans;
    }
};

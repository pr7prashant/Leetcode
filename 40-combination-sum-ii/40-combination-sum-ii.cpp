class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& candidates, int target, int start, vector<int>& curr) {
        if (target == 0) return res.push_back(curr);
        
        if (target < 0 || start == candidates.size()) return;
        
        for (int i = start; i < candidates.size(); i++) {
            if (i == start || candidates[i] != candidates[i-1]) {
                curr.push_back(candidates[i]);
                solve(candidates, target - candidates[i], i + 1, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(candidates, target, 0, curr);
        return res;
    }
};

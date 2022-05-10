class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int k, int n, int start, vector<int>& curr, vector<bool>& used) {
        if (k == 0 && n == 0) ans.push_back(curr);
        
        if (k == 0 || n < 0) return;
        
        for (int i = start; i <= 9; i++) {
            if (!used[i]) {
                used[i] = true;
                curr.push_back(i);
                solve(k-1, n - i, i + 1, curr, used);
                curr.pop_back();
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> used(10, false);
        vector<int> curr;
        solve(k, n, 1, curr, used);
        return ans;
    }
};

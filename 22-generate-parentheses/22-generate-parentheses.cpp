class Solution {
public:
    void helper(int n, int open, string curr, vector<string>& ans) {
        if (n == 0) {
            if (open == 0) ans.push_back(curr);
            return;
        }
        
        helper(n-1, open+1, curr + "(", ans);
        if (open > 0) {
            helper(n-1, open-1, curr + ")", ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(2*n, 0, "", ans);
        return ans;
    }
};

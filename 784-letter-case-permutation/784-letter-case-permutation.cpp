class Solution {
public:
    void helper(string& s, int start, vector<string>& ans) {
        if (start == s.length()) return ans.push_back(s);    
        
        if (s[start] >= '0' && s[start] <= '9') {
            helper(s, start+1, ans);
            return;
        }
        
        s[start] = toupper(s[start]);
        helper(s, start+1, ans);
        s[start] = tolower(s[start]);
        helper(s, start+1, ans);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(s, 0, ans);
        return ans;
    }
};

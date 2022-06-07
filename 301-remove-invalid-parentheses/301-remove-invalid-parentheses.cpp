class Solution {
public:
    vector<string> res;
    unordered_map<string, bool> mp;
    
    int countInvalid(string& s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            
            if (s[i] == ')' && !stk.empty() && stk.top() == '(') stk.pop();
            else stk.push(s[i]);
        }
        
        return stk.size();
    }
    
    void solve(string& s, int invalids) {
        if (invalids < 0) return;
        
        if (invalids == 0 && countInvalid(s) == 0) {
            res.push_back(s);
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            
            string left = s.substr(0, i);
            string right = s.substr(i+1, s.length() - i - 1);
            string temp = left + right;
            
            if (mp.find(temp) == mp.end()) {
                mp[temp] = true;
                solve(temp, invalids - 1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int invalids = countInvalid(s);
        solve(s, invalids);
        return res;
    }
};

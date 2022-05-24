class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || stk.empty()) stk.push(i);
            else if (s[i] == ')' && s[stk.top()] == '(') stk.pop();
            else stk.push(i);
        }
        
        if (stk.empty()) return s.length();
        
        int ans = s.length() - stk.top() - 1;
        while (!stk.empty()) {
            int b = stk.top();
            stk.pop();
            if (stk.empty()) {
                ans = max(ans, b);
            } else {
                ans = max(ans, b - stk.top() - 1); 
            }
        }
        
        return ans;
    }
};

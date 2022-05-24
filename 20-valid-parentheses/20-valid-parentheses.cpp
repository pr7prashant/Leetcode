class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } else if (ch == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else stk.push(ch);
            } else if (ch == '}') {
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else stk.push(ch);
            } else if (ch == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else stk.push(ch);
            }
        }        
        
        return stk.empty();
    }
};

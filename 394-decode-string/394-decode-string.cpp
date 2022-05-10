class Solution {
public:
    stack<char> stk;
    
    string decodeString(string s) {
        string ans = "";
        for (char ch : s) {
            if (ch != ']') {
                stk.push(ch);
                continue;
            }
            
            string curr = "";
            while (stk.top() != '[') {
                curr = stk.top() + curr;
                stk.pop();
            }
            stk.pop();
            
            string num = "";
            while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
                num = stk.top() + num;
                stk.pop();
            }
            int t = stoi(num);
            while (t--) {
                for (char c : curr) stk.push(c);
            }
        }
        
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};

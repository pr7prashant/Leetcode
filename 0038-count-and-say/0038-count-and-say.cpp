class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prev = countAndSay(n-1);
        string ans = "";
        int count = 0;
        char curr = prev[0];
        for (char ch : prev) {
            if (ch == curr) {
                count++;
            } else {
                ans += to_string(count) + curr;
                curr = ch;
                count = 1;
            }
        }
        ans += to_string(count) + curr;
        
        return ans;
    }
};
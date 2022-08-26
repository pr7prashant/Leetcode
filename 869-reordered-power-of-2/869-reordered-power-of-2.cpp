class Solution {
public:
    bool isPowerOf2(int n) {
        int p = 1;
        while (p < n) p <<= 1;
        return p == n;
    }
    
    bool helper(string s, int start) {
        if (isPowerOf2(stoi(s))) return true;
        
        bool ans = false;
        for (int i = start; i < s.length(); i++) {
            if (start == 0 && s[i] == '0') continue;
            swap(s[start], s[i]);
            ans |= helper(s, start + 1);
            swap(s[start], s[i]);
        }
        
        return ans;
    }
    
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        return helper(num, 0);
    }
};

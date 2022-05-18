class Solution {
public:
    string longestPrefix(string s) {
        long long lhash = 0, rhash = 0, mod = 1e9 + 7, p = 1;
        int i = 0, j = s.length() - 1, ans = 0;
        
        while (i < s.length() - 1) {
            lhash = ((lhash * 128) + s[i]) % mod;
            rhash = ((s[j] * p) + rhash) % mod;
            p = (p * 128) % mod;
            
            if (lhash == rhash) ans = i + 1; 
            
            i++;
            j--;
        }
        
        return s.substr(0, ans);;
    }
};

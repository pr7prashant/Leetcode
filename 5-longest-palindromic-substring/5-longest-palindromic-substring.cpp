class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        vector<vector<int>> pal(len, vector<int>(len, 0));
        
        int start = 0, size = 1;
        for (int i = 0; i < len; i++) {
            pal[i][i] = 1;
            if (i + 1 < len && s[i] == s[i+1]) {
                pal[i][i+1] = 1;
                start = i;
                size = 2;
            }
        }
        
        int k = 2;
        while (k < len) {
            for (int i = 0; i < len - k; i++) {
                if (pal[i+1][i+k-1] == 1 && s[i] == s[i+k]) {
                    pal[i][i+k] = 1;
                    
                    if (k + 1 > size) {
                        start = i;
                        size = k + 1;
                    }
                }
            }
            
            k++;
        }
        
        return s.substr(start, size);
    }
};

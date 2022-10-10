class Solution {
public:
    string breakPalindrome(string pal) {
        if (pal.length() == 1) return "";
        
        for (int i = 0; i < pal.length() / 2; i++) {
            if (pal[i] != 'a') {
                pal[i] = 'a';
                return pal;
            }
        }
        
        pal[pal.length() - 1] = 'b';
        
        return pal;
    }
};
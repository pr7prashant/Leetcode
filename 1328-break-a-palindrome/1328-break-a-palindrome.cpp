class Solution {
public:
    bool isPalindrome(string& str) {
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - i - 1]) return false;
        }
        return true;
    }
    
    string breakPalindrome(string pal) {
        if (pal.length() == 1) return "";
        
        bool changed = false;
        for (int i = 0; i < pal.length() && !changed; i++) {
            for (char ch = 'a'; ch < pal[i]; ch++) {
                char og = pal[i];
                pal[i] = ch;
                if (!isPalindrome(pal)) {
                    changed = true;
                    break;
                }
                pal[i] = og;
            }
        }
        
        if (!changed) pal[pal.length() - 1] = 'b';
        
        return pal;
    }
};
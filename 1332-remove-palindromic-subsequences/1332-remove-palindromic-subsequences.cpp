class Solution {
public:
    bool isPalindrome(string& s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if (s == "") return 0;
        if (isPalindrome(s)) return 1;
        int count_a = 0, count_b = 0;
        for (char ch : s) {
            if (ch == 'a' && count_a == 0) count_a++;
            if (ch == 'b' && count_b == 0) count_b++;
        }
        return count_a + count_b;
    }
};

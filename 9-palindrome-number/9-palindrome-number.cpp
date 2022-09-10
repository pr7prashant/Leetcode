class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int n = x, p = 0;
        long long rev = 0;
        
        while (pow(10, p) <= x) p++;
        
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            rev += d * pow(10, --p);
            if (rev > INT_MAX) return false;
        }
        
        return x == rev;
    }
};

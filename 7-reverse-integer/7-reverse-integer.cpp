class Solution {
public:
    int reverse(int x) {
        int p = 0;
        long long rev = 0;
        bool isNegative = x < 0 ? true : false;
        x = abs(x);
        
        while (pow(10,p) <= x) p++;
        // cout << p << endl;
        while (x > 0) {
            int d = x % 10;
            // cout << d << " ";
            x /= 10;
            rev += d * pow(10, --p);
            if (rev > INT_MAX) return 0;
            // cout << rev << endl;
        }
        
        if (isNegative) rev *= -1;
        
        return rev;
    }
};

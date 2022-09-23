class Solution {
public:
    long long MOD = 1e9 + 7;
    
    int intToBinaryLength(int n) {
        int len = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) len = i+1;
        }
        return len;
    }
    
    int concatenatedBinary(int n) {
        if (n == 0) return 0;
        int len = intToBinaryLength(n);
        long long prev = concatenatedBinary(n-1);
        return ((prev << len) + n) % MOD;
    }
};
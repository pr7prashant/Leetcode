class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int p = 0;
        while (pow(3, p) < n) p++;
        return pow(3, p) == n;
    }
};

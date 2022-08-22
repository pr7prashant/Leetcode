class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        int i = 0;
        while (pow(4, i) < n) i++;
        return pow(4, i) == n;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits(32);
        for (int i = 0; i < 32; i++) bits[i] = ((1 << i) & n) ? 1 : 0;
        
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] == 1) ans += pow(2, 32 - i - 1);
        }
        
        return ans;
    }
};
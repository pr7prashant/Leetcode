class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0;
        for (int n : nums) x1 ^= n;
        for (int i = 0; i <= nums.size(); i++) x2 ^= i;
        return x1 ^ x2;
    }
};

class Solution {
public:
    int minSwaps(string s) {
        int open = 0, swap = 0;
        for (char ch : s) {
            if (ch == '[') open++;
            else {
                if (open == 0) {
                    swap++;
                    // open++;
                }
                else open--;
            }
        }
        return (swap + 1) / 2;
    }
};

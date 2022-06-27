class Solution {
public:
    int minPartitions(string n) {
        int mx = INT_MIN;
        for (char ch : n) mx = max(mx, ch-'0');
        return mx;
    }
};

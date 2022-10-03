class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, ans = 0, len = colors.length();
        while (i < len) {
            int total = 0, mx = INT_MIN;
            char c = colors[i];
            while(i < len && colors[i] == c) {
                total += neededTime[i];                
                mx = max(mx, neededTime[i]);
                i++;
            }
            ans += total - mx;
        }
        return ans;
    }
};
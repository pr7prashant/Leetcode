class Solution {
public:
    int MOD = 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.insert(horizontalCuts.end(), h);
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.end(), w);
        
        int maxH = 0, maxV = 0;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxV = max(maxV, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return ((long long)maxH  * (long long)maxV) % MOD;
    }
};

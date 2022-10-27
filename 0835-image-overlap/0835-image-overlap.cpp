class Solution {
public:
    int getOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int dx, int dy) {
        int overlap = 0;
        for (int i = 0; i < img1.size(); i++) {
            for (int j = 0; j < img1[0].size(); j++) {
                if (i+dx < 0 || i+dx >= img1.size() || j+dy < 0 || j+dy >= img1[0].size()) continue;
                if (img1[i+dx][j+dy] == 1 && img2[i][j] == 1) overlap++; 
            }
        }
        return overlap;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        for (int dx = -(int)img1.size(); dx < (int)img1.size(); dx++) {
            for (int dy = -(int)img1[0].size(); dy < (int)img1[0].size(); dy++) {
                ans = max(ans, getOverlap(img1, img2, dx, dy));
            }
        }
        return ans;
    }
};
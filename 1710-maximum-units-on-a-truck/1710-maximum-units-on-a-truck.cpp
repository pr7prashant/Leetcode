class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& b1, vector<int>& b2) {
            return b1[1] > b2[1];
        });
        
        int ans = 0;
        for (vector<int>& b : boxTypes) {
            int temp = min(b[0], truckSize);
            ans += temp * b[1];
            truckSize -= temp;
            
            if (truckSize == 0) return ans;
        }
        
        return ans;
    }
};

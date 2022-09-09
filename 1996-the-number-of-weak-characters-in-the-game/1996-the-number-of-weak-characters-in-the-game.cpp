class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int ans = 0, mn = INT_MIN;
        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < mn) ans++;
            mn = max(mn, properties[i][1]);
        }        
        
        return ans;
    }
};

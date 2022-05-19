class Solution {
public:
    int minFlips(string s) {
        // Pattern 1 - 101010...
        // Flips required = count 0's at even and 1's at odd places
        // Pattern 2 - 010101...
        // Flips required = count 1's at even and 0's at odd places
        
        // cnt[0][0] = number of '0' in even positions
        // cnt[0][1] = number of '0' in odd  positions
        // cnt[1][0] = number of '1' in even positions
        // cnt[1][1] = number of '1' in odd  positions
        
        int len = s.length();
        vector<vector<int>> cnt(2, vector<int>(2, 0));
        int ans = INT_MAX;
        
        // Calculate count of 0's and 1's at odd and even places
        for (int i = 0; i < len; i++) cnt[s[i] - '0'][i % 2]++;
        
        ans = min(ans, cnt[0][0] + cnt[1][1]);
        ans = min(ans, cnt[1][0] + cnt[0][1]);
        
        // Check with Remove operation 
        for (int i = 0; i < len; i++) {
            // Remove from front
            cnt[s[i] - '0'][i % 2]--;
            // Add at back
            cnt[s[i] - '0'][(i+len) % 2]++;
            
            ans = min(ans, cnt[0][0] + cnt[1][1]);
            ans = min(ans, cnt[1][0] + cnt[0][1]);
        }

        return ans;
    }
};

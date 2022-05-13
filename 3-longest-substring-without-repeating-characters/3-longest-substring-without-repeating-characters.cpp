class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> used(128, false);      
        int i = 0, j = 0, ans = 0;
        while (j < s.length()) {
            if (!used[s[j]]) {
                used[s[j]] = true;
                ans = max(ans, j - i + 1);
                j++;
            } else {
                used[s[i]] = false;
                i++;
            }
        }
        return ans;
    }
};

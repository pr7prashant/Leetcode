class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++) {
            char curr = strs[0][i];
            for (string& s : strs) {
                if (i == s.length() || s[i] != curr) return ans;
            }
            ans += curr;
        }
        return ans;
    }
};

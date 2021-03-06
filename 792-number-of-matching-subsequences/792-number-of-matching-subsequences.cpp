class Solution {
public:
    unordered_map<string,bool> dp;
    
    bool isSubsequence(string& s1, string& s2) {
        if (dp.find(s2) != dp.end()) return dp[s2];
        
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) j++;
            i++;
        }
        
        return dp[s2] = j == s2.length();
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string& w : words) {
            if (isSubsequence(s, w)) count++;
        }
        return count;
    }
};

class Solution {
public:
    bool isMatching(string& w1, string& w2) {
        if (w1.length() != w2.length()) return false;
        
        unordered_map<char,char> mp1, mp2;
        for (int i = 0; i < w1.length(); i++) {
            if (mp1.find(w1[i]) == mp1.end() && mp2.find(w2[i]) == mp2.end()) {
                mp1[w1[i]] = w2[i];
                mp2[w2[i]] = w1[i];
            } else if (mp1.find(w1[i]) == mp1.end() || mp2.find(w2[i]) == mp2.end() || mp1[w1[i]] != w2[i] || mp2[w2[i]] != w1[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (string& w : words) {
            if (isMatching(w, pattern)) result.push_back(w);
        }
        return result;
    }
};

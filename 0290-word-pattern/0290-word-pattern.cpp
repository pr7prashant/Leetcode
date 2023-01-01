class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);
        
        if (words.size() != pattern.length()) return false;
        
        unordered_map<string, char> mp1;
        unordered_map<char, string> mp2;
        for (int i = 0; i < pattern.length(); i++) {
            if (mp1.find(words[i]) != mp1.end() && mp1[words[i]] != pattern[i]) return false;
            if (mp2.find(pattern[i]) != mp2.end() && mp2[pattern[i]] != words[i]) return false;
            mp1[words[i]] = pattern[i];
            mp2[pattern[i]] = words[i];
        }
        
        return true;
    }
};

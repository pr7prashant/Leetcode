class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool checkCombinations(int k, string str) {
        if (k == 0) return mp.find(str) == mp.end() ? false : true;
        return checkCombinations(k-1, str + "0") && checkCombinations(k-1, str + "1");
    }
    
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;
        
        for (int i = 0; i <= s.length() - k; i++) {
            mp[s.substr(i, k)] = true;
        }
        
        return checkCombinations(k, "");
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        res.push_back(s[0]);
        
        for (int i = 1; i < s.length(); i++) {
            if (res.length() > 0 && s[i] == res.back()) {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};

class Solution {
public:
    bool isValid(string str, unordered_map<string,int>& count, int wLen) {
        unordered_map<string,int> duplicate;
        for (int i = 0; i < str.length(); i += wLen) {
            string key = str.substr(i, wLen);
            duplicate[key] += 1;
        }
        return count == duplicate;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int sLen = s.length();
        int wLen = words[0].length();
        int total_len = wLen * words.size();
        
        if (sLen < total_len) return ans;
        
        unordered_map<string,int> count;
        for (string& w : words) count[w] += 1;
        
        
        for (int i = 0; i <= sLen - total_len; i++) {
            string substr = s.substr(i, total_len);
            if (isValid(substr, count, wLen)) ans.push_back(i);    
        }
        
        return ans;
    }
};

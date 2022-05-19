class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> seen(128, false);
        vector<int> last(128, -1);
        for (int i = 0; i < s.length(); i++) last[s[i]] = i;
        
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (seen[s[i]]) continue;
                
            while (ans.length() > 0 && ans.back() > s[i] && last[ans.back()] > i) {
                seen[ans.back()] = false;
                ans.pop_back();   
            }
            
            ans.push_back(s[i]);
            seen[s[i]] = true;
        }        
        
        return ans;
    }
};

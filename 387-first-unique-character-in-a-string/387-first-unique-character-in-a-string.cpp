class Solution {
public:
    int firstUniqChar(string s) {
        vector<bool> seen(26, false);
        list<pair<char,int>> ls;
        for (int i = 0; i < s.length(); i++) {
            if (seen[s[i] - 'a']) {
                auto it = find_if(ls.begin(), ls.end(), [&](const pair<char,int> v) { return v.first == s[i]; });
                if (it != ls.end()) ls.erase(it);
            } else {
                ls.push_back({ s[i], i });
                seen[s[i] - 'a'] = true;
            }
        }
        
        return ls.empty() ? -1 : ls.begin()->second;
    }
};

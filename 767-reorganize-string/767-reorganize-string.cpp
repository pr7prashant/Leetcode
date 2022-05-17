class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        char mx = s[0];
        
        for (char ch : s) {
            mp[ch]++;
            if (mp[ch] > mp[mx]) mx = ch;
        }
        
        if (mp[mx] > (s.length() + 1) / 2) return "";
        
        int i = 0;
        for (int j = 0; j < mp[mx]; j++) {
            s[i] = mx;
            i += 2;
        }
        
        mp[mx] = 0;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            while (it->second > 0) {
                if (i >= s.length()) i = 1;
                
                s[i] = it->first;
                it->second--;
                i += 2;
            }
        }
        
        return s;
    }
};

class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while (i < s.length() - 1) {
            //cout << i << " : " << s << endl;
            if (s.length() <= 1) return s;
            
            if (tolower(s[i]) == tolower(s[i+1]) && s[i] != s[i+1]) {
                s = s.substr(0, i) + s.substr(i+2);
                i = max(0, i-1);
            } else {
                i++;
            }
        }
        return s;
    }
};
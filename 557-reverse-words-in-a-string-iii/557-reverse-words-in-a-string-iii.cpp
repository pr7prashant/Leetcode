class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stringstream ss(s);
        string token;
        
        while (getline(ss, token, ' ')) {
            if (res.length() > 0) res += " ";
            int len = token.length();
            for (int i = 0; i < len/2; i++) {
                swap(token[i], token[len-i-1]);
            }
            res += token;
        }
        
        return res;
    }
};
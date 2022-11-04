class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,bool> vowels;
        vowels['a'] = true;
        vowels['A'] = true;
        vowels['e'] = true;
        vowels['E'] = true;
        vowels['i'] = true;
        vowels['I'] = true;
        vowels['o'] = true;
        vowels['O'] = true;
        vowels['u'] = true;
        vowels['U'] = true;
        
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!vowels.count(s[i])) i++;
            if (!vowels.count(s[j])) j--;   
            if (vowels.count(s[i]) && vowels.count(s[j])) swap(s[i++], s[j--]);
        }
        return s;
    }
};
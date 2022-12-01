class Solution {
public:
    bool halvesAreAlike(string s) {
        int i = 0, j = s.length() - 1, countl = 0, countr = 0;
        while (i < j) {
            char l = tolower(s[i++]), r = tolower(s[j--]);
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') countl++;
            if (r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u') countr++;
        }
        return countl == countr;
    }
};
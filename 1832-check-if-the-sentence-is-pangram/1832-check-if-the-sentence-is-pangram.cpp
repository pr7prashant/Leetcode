class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> letters(26, false);
        for (char ch : sentence) letters[ch - 'a'] = true;
        for (bool b : letters) if (!b) return false;
        return true;
    }
};
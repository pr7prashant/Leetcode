class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, w2 = 0, i = 0, j = 0;
        while (w1 < word1.size() && w2 < word2.size()) {
            if (word1[w1][i++] != word2[w2][j++]) return false;
            if (i == word1[w1].length()) {
                w1++;
                i = 0;
            }
            if (j == word2[w2].length()) {
                w2++;
                j = 0;
            }
        }
        return (w1 == word1.size() && w2 == word2.size());
    }
};
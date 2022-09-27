class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> left(dominoes.length(), INT_MAX);
        vector<int> right(dominoes.length(), INT_MAX);
        
        int prev = -1;
        for (int i = dominoes.length() - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                prev = i;
                left[i] = 0;
            } else if (dominoes[i] == 'R') {
                prev = -1;
            } else if (prev != -1) {
                left[i] = prev - i;
            }
        }
        prev = -1;
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == 'R') {
                prev = i;
                right[i] = 0;
            } else if (dominoes[i] == 'L') {
                prev = -1;
            } else if (prev != -1) {
                right[i] = i - prev;
            }
        }
        
        string res = "";
        for (int i = 0; i < dominoes.length(); i++) {
            if (left[i] < right[i]) res += "L";
            else if (left[i] > right[i]) res += "R";
            else res += ".";
        }
        
        return res;
    }
};
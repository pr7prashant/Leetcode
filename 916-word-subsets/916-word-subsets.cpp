class Solution {
public:
    bool isUniversal(string word, vector<int>& count) {
        vector<int> temp = getCount(word);
        for (int i = 0; i < 26; i++) {
            if (temp[i] < count[i]) return false;
        }
        return true;
    }
    
    vector<int> getCount(string& str) {
        vector<int> temp(26, 0);
        for (char ch : str) temp[ch - 'a']++;
        return temp;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26, 0);
        for (string& w : words2) {
            vector<int> temp = getCount(w);
            for (int i = 0; i < 26; i++) {
                count[i] = max(count[i], temp[i]);
            }
        }
        
        vector<string> res;
        for (string& word : words1) {
            if (isUniversal(word, count)) res.push_back(word);
        }
        
        return res;
    }
};

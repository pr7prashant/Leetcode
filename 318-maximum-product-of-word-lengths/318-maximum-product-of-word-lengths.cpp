class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        for (string& word : words) {
            int mask = 0;
            for (char ch : word) {
                int pos = ch - 'a';
                mask |= 1 << pos;
            }
            masks.push_back(mask);
        }
        
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if ((masks[i] & masks[j]) == 0) {
                    int len = words[i].length() * words[j].length();
                    ans = max(ans, len);
                }
            }
        }
        
        return ans;
    }
};

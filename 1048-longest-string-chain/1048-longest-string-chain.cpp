class Solution {
public:
    unordered_map<string, int> dp;
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& w1, string& w2) {
            return w2.length() > w1.length();
        });      
        
        int ans = 1;
        for (string& word : words) {
            for (int i = 0; i < word.length(); i++) {
                string s = word.substr(0, i) + word.substr(i+1);
                int res = dp.find(s) == dp.end() ? 1 : dp[s] + 1;
                dp[word] = max(dp[word], res);
            }
            ans = max(ans, dp[word]);
        }
        
        return ans;
    }
};

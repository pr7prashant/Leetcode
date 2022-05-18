class Solution {
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (string word : strs) {
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(word);
        }
        
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};

class Solution {
public:
    bool isPalindrome(string& str, int start, int end) {
        while (start < end) {
            if (str[start++] != str[end--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> mp;
        for (int i = 0; i < words.size(); i++) mp[words[i]] = i;
        
        for (int i = 0; i < words.size(); i++) {
            // 1. Empty string : check if other string is palindrome
            if (words[i] == "") {
                for (int j = 0; j < words.size(); j++) {
                    if (i != j && isPalindrome(words[j], 0, words[j].length() - 1)) {
                        ans.push_back({ i, j });
                        ans.push_back({ j, i });
                    }
                }
                continue;
            }
            
            // 2. Reverse of string is present
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if (mp.count(rev) && mp[rev] != i) {
                ans.push_back({ i, mp[rev] });
            }
            
            // 3. cut[i+1] is palindrome and reverse cut[0:i] is present
            // 4. cut[0:i] is palindrome and reverse cut[i+1] is present
            string str = words[i];
            for (int j = 1; j < rev.length(); j++) {
                if (isPalindrome(rev, j, str.length() - 1)) {
                    string revL = rev.substr(0, j);
                    if (mp.count(revL)) ans.push_back({ mp[revL], i });
                }
                
                if (isPalindrome(rev, 0, j - 1)) {
                    string revR = rev.substr(j);
                    if (mp.count(revR)) ans.push_back({ i, mp[revR] });
                }
            }
        }
        
        return ans;
    }
};

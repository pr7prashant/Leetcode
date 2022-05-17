class Solution {
public:
    string minWindow(string s, string t) {
        if (s == t) return t;
        if (s.length() < t.length()) return "";
        
        vector<int> arr(128, 0);
        int count = 0;
        for (char ch : t) {
            arr[ch]++;
            if (arr[ch] == 1) count++;
        }
        
        int i = 0, j = 0;
        string ans = "";
        while (j < s.length()) {
            if (--arr[s[j]] == 0) count--;
            
            while (count == 0) {
                string temp = s.substr(i, j - i + 1);
                if (ans == "") ans = temp;
                ans = temp.length() < ans.length() ? temp : ans;
                if (arr[s[i++]]++ == 0) count++;
            }
            
            j++;
        }
        
        return ans;
    }
};

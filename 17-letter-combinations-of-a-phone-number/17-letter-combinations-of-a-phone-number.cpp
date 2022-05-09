class Solution {
public:
    vector<string> res;
    unordered_map<char, vector<char>> mp;
    
    Solution() {
        mp['2'] = { 'a', 'b', 'c' };
        mp['3'] = { 'd', 'e', 'f' };
        mp['4'] = { 'g', 'h', 'i' };
        mp['5'] = { 'j', 'k', 'l' };
        mp['6'] = { 'm', 'n', 'o' };
        mp['7'] = { 'p', 'q', 'r', 's' };
        mp['8'] = { 't', 'u', 'v' };
        mp['9'] = { 'w', 'x', 'y', 'z' };
    }
    
    void solve(string& digits, int i, string ans) {
        if (i > 0 && i == digits.size()) return res.push_back(ans);
        
        char curr = digits[i];
        for (char ch : mp[curr]) {
            ans += ch;
            solve(digits, i+1, ans);
            ans.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        solve(digits, 0, "");
        return res;
    }
};

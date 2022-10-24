class Solution {
public:
    bool isUnique(string str) {
        unordered_map<char,bool> mp;
        for (char ch : str) {
            if (mp.count(ch)) return false;
            mp[ch] = true;
        }
        return true;
    }
    
    int solve(vector<string>& arr, string str, int curr) {
        if (curr == arr.size()) return str.length();
        
        if (isUnique(str + arr[curr])) {
            return max(solve(arr, str+arr[curr], curr+1), solve(arr, str, curr+1));
        }
        
        return solve(arr, str, curr+1);
    }
    
    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0);
    }
};
class Solution {
public:
    vector<int> ans;
    
    void solve(string curr, int n, int k) {
        if (curr.length() == n) return ans.push_back(stoi(curr));
        
        int num = curr.back() - '0';
        if (num-k >= 0) solve(curr + to_string(num-k), n, k);
        if (num+k <= 9 && k != 0) solve(curr + to_string(num+k), n, k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; i++) solve(to_string(i), n, k);
        return ans;
    }
};

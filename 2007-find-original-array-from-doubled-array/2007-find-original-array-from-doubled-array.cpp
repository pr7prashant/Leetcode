class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        if (changed.size() & 1) return ans;
        
        map<int,int> mp;
        for (int n : changed) mp[n]++;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int n = it->first;
            if (mp[n] == 0) continue;
            if (!mp.count(2*n) || mp[n] > mp[2*n]) return vector<int>();
            int m = n == 0 ? mp[n]/2 : min(mp[n], mp[2*n]);
            mp[n] -= m;
            mp[2*n] -= m;
            for (int i = 0; i < m; i++) ans.push_back(n);
        }
        
        return ans;
    }
};

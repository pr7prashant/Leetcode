class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count, mp;
        for (int i : arr) count[i]++;
        for (auto [k,v] : count) if (++mp[v] > 1) return false;
        return true;
    }
};
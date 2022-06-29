class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2) {
            if (p1[0] != p2[0]) return p1[0] > p2[0];
            return p1[1] < p2[1];
        });
        
        for (vector<int>& p : people) res.insert(res.begin() + p[1], p);
        
        return res;
    }
};

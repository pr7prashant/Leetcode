class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2) {
            return e1[0] == e2[0] ? e2[1] < e1[1] : e1[0] < e2[0];
        });
        
        vector<int> temp;
        for (vector<int>& e : envelopes) {
            if (temp.empty() || temp.back() < e[1]) {
                temp.push_back(e[1]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), e[1]) - temp.begin();
                temp[idx] = e[1];
            }
        }
        
        return temp.size();
    }
};

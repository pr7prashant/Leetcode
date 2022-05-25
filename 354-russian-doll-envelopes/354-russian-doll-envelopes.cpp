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
                // int idx = lower_bound(temp.begin(), temp.end(), e[1]) - temp.begin();
                // temp[idx] = e[1];
                
                int l = 0, r = temp.size() - 1;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (e[1] > temp[mid]) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                temp[l] = e[1];
            }
        }
        
        return temp.size();
    }
};

// 3,4,4,7
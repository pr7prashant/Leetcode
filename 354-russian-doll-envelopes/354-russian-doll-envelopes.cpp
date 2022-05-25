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
                int start = 0, end = temp.size() - 1;
                while (start < end) {
                    int mid = start + (end - start) / 2;
                    if (e[1] > temp[mid]) {
                        start = mid + 1;
                    } else {
                        end = mid;
                    }
                }
                temp[start] = e[1];
            }
        }
        
        return temp.size();
    }
};

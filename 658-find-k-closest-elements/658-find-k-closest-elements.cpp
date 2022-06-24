class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        
        for (int n : arr) {
            pq.push({abs(x - n), n});
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

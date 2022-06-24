class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int n : nums) mp[n]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int num = it->first;
            int freq = it->second;
            
            if (pq.size() < k || freq > pq.top().first) pq.push({ freq, num });
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

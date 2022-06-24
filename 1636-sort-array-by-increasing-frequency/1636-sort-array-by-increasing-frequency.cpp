class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for (int n : nums) mp[n]++;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }
        
        vector<int> res;
        while (!pq.empty()) {
            vector<int> temp;
            auto [f,n] = pq.top();
            pq.pop();
            
            for (int i = 0; i < f; i++)
                temp.push_back(n);
            
            while (!pq.empty()) {
                auto [freq,num] = pq.top();
                if (freq != f) break;
                
                pq.pop();
                for (int i = 0; i < freq; i++)
                    temp.push_back(num);
            }
            
            sort(temp.begin(), temp.end(), greater<int>());
            res.insert(res.end(), temp.begin(), temp.end());
        }
        
        return res;
    }
};

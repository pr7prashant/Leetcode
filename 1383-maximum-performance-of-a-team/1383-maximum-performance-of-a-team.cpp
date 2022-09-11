class Solution {
public:
    int MOD = 1e9 + 7;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers;
        for (int i = 0; i < n; i++) engineers.push_back({ efficiency[i], speed[i] });
        sort(engineers.begin(), engineers.end(), greater<pair<int,int>>());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0, v = 0;
        for (pair<int,int>& eng : engineers) {
            auto [e,s] = eng;
            pq.push(s);
            v += s;
            
            if (pq.size() > k) {
                v -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, v * e);
        }
        
        return ans % MOD;
    }
};

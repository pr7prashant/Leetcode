class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for (char ch : s) count[ch - 'a']++;
        
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) pq.push({ count[i], 'a' + i });
        }
        
        int ans = 0;
        while (pq.size() > 1) {
            auto [n, ch] = pq.top();
            pq.pop();
            
            if (n == pq.top().first) {
                ans++;
                if (n > 1) pq.push({ n - 1, ch });
            }
        }
        
        return ans;
    }
};

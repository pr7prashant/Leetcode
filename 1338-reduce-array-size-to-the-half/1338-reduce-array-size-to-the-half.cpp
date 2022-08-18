class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int n : arr) freq[n]++;
        
        priority_queue<pair<int,int>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push({ it->second, it->first });
        }
        
        int size = arr.size(), count = 0;
        while (size > arr.size() / 2) {
            auto [f,n] = pq.top();
            pq.pop();
            size -= f;
            count++;
        }
        
        return count;
    }
};

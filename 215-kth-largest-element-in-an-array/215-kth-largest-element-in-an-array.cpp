class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int n : nums) {
            if (pq.size() < k || n > pq.top()) pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        
        return pq.top();
    }
};

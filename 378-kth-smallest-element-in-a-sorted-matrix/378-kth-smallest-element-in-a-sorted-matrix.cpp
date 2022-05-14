class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;                
        
        for (int i = 0; i < matrix.size(); i++) {
            pq.push({ matrix[i][0], i, 0 });
        }
        
        int ans;
        while (k--) {
            auto [num, m, i] = pq.top();
            pq.pop();
            ans = num;
            
            if (i + 1 < matrix[m].size()) {
                pq.push({ matrix[m][i+1], m, i+1 });
            }
        }
        
        return ans;
    }
};

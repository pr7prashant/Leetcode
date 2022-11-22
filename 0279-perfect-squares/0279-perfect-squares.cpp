class Solution {
public:
    int numSquares(int n) {
        unordered_map<int,bool> visited;
        queue<pair<int,int>> q;
        q.push({n, 0});
        
        while (!q.empty()) {
            auto [rem, count] = q.front();
            q.pop();
            
            if (rem == 0) return count;
            
            for (int i = 1; i*i <= rem; i++) {
                int next = rem - i*i;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({ next, count + 1 });
                }
            }
        }
        
        return -1;
    }
};
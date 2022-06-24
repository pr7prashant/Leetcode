class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, vector<int>>> pq;
        
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            double d = (double)(x*x + y*y);
            pq.push({d, {x,y}});
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        
        return res;
    }
};

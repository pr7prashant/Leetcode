class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int i = 0, stops = 0, maxDistance = startFuel;
        while (maxDistance < target) {
            while (i < stations.size() && maxDistance >= stations[i][0]) {
                pq.push(stations[i++][1]);
            }
            
            if (pq.empty()) return -1;
            
            maxDistance += pq.top();
            pq.pop();
            stops++;
        }
        
        return stops;
    }
};

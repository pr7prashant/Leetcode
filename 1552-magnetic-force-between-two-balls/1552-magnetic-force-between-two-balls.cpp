class Solution {
public:
    bool isValidGap(vector<int>& position, int gap, int m) {
        m--;
        int prev = 0;
        for (int i = 1; i < position.size(); i++) {
            if (m == 0) return true;
            if (position[i] >= position[prev] + gap) {
                prev = i;
                m--;
            }
        }

        return m == 0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int start = 1, end = position.back() - position.front(), ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (isValidGap(position, mid, m)) {
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};

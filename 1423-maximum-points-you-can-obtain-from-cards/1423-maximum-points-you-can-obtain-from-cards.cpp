class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> presum(cardPoints.begin(), cardPoints.end());
        presum.insert(presum.begin(), 0);
        for (int i = 1; i < presum.size(); i++) presum[i] += presum[i-1];
        
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            int left = presum[i];
            int right = presum[len] - presum[len-k+i];
            ans = max(ans, left + right);
        }
        
        return ans;
    }
};

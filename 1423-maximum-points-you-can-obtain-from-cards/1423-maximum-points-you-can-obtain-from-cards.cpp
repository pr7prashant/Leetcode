class Solution {
public:
//     unordered_map<string,int> dp;
    
//     int solve(vector<int>& cardPoints, int k, int start, int end) {
//         if (k == 0) return 0;
        
//         string key = to_string(start) + "_" + to_string(end) + "_" + to_string(k);
//         if (dp.find(key) != dp.end()) return dp[key];
        
//         return dp[key] = max(
//             cardPoints[start] + solve(cardPoints, k-1, start+1, end),
//             cardPoints[end] + solve(cardPoints, k-1, start, end-1)
//         );
//     }
    
    int maxScore(vector<int>& cardPoints, int k) {
        // return solve(cardPoints, k, 0, cardPoints.size() - 1);
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

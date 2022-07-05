class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        set<int> st(nums.begin(), nums.end());
        int count = 1, ans = 1;
        for (int n : st) {
            if (st.find(n - 1) != st.end()) continue;
            
            int next = n + 1;
            while (st.find(next) != st.end()) {
                count++;
                next += 1;
            }
            ans = max(ans, count);
            count = 1;
        }
        
        return ans;
    }
};

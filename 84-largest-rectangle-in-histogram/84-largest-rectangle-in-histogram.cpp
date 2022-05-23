class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> spanLeft(heights.size());
        vector<int> spanRight(heights.size());
        stack<int> stk;
        
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            
            if (!stk.empty()) spanLeft[i] = i - stk.top();
            else spanLeft[i] = i + 1;
                
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            
            if (!stk.empty()) spanRight[i] = stk.top() - i;
            else spanRight[i] = heights.size() - i;
                
            stk.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int span = spanLeft[i] + spanRight[i] - 1;
            ans = max(ans, span * heights[i]);
        }
        
        return ans;
    }
};

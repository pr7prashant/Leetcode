class StockSpanner {
public:
    vector<int> prices;
    stack<int> stk;
    
    int next(int price) {
        prices.push_back(price);
        while (!stk.empty() && prices[stk.top()] <= price) stk.pop();
        int ans = stk.empty() ? prices.size() : prices.size() - stk.top() - 1;
        stk.push(prices.size() - 1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
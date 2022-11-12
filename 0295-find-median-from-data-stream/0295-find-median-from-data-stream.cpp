class MedianFinder {
public:
    priority_queue<int> sm;
    priority_queue<int, vector<int>, greater<int>> lg;
    
    void balance() {
        if ((int)(sm.size() - lg.size()) > 1) {
            int top = sm.top();
            sm.pop();
            lg.push(top);
        }
        
        if ((int)(lg.size() - sm.size()) > 1) {
            int top = lg.top();
            lg.pop();
            sm.push(top);
        }
    }
    
    void addNum(int num) {
        if (sm.empty() && lg.empty()) {
            sm.push(num);
            return;
        }
        
        double currMedian = findMedian();
        
        if (num > currMedian) lg.push(num);
        else sm.push(num);
        
        balance();
    }
    
    double findMedian() {
        if (sm.size() > lg.size()) return (double)sm.top();
        
        if (lg.size() > sm.size()) return (double)lg.top();
        
        return (double)(sm.top() + lg.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
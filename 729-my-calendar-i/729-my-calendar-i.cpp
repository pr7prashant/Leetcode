class MyCalendar {
public:
    vector<pair<int,int>> intervals;
    
    MyCalendar() { }
    
    bool book(int start, int end) {
        bool hasConflict = false;
        for (pair<int,int>& interval : intervals) {
            auto [s, e] = interval;
            if ((start <= s && end <= s) || (start >= e && end >= e)) continue;
            hasConflict = true;
            break;
        }
        
        if (!hasConflict) {
            intervals.push_back({ start, end });
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

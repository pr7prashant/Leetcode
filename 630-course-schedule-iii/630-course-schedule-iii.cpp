class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& c1, vector<int>& c2) {
           return c1[1] < c2[1]; 
        });
        
        priority_queue<vector<int>> pq;
        int time = 0, count = 0;
        
        for (vector<int>& course : courses) {
            if (time + course[0] <= course[1]) {
                time += course[0];
                count++;
                pq.push(course);
            } else if (!pq.empty()) {
                vector<int> top = pq.top();
                if (course[0] < top[0]) {
                    time -= top[0];
                    pq.pop();
                    time += course[0];
                    pq.push(course);
                }
            }
        }
        
        return count;
    }
};

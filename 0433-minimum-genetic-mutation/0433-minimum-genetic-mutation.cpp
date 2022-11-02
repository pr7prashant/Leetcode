class Solution {
public:
    vector<char> genes = { 'A', 'C', 'G', 'T' };
    unordered_map<string,bool> mp;
    unordered_map<string,bool> visited;
    
    int minMutation(string start, string end, vector<string>& bank) {
        for (string& str : bank) mp[str] = true;
        
        queue<pair<string,int>> q;
        q.push({ start, 0 });
        
        while (!q.empty()) {
            auto [curr,d] = q.front();
            q.pop();
            
            if (curr == end) return d;
            
            for (int i = 0; i < curr.size(); i++) {
                for (char ch : genes) {
                    char og = curr[i];
                    curr[i] = ch;
                    if (mp.count(curr) && !visited.count(curr)) {
                        visited[curr] = true;
                        q.push({ curr, d + 1 });
                    }
                    curr[i] = og;
                }
            }
        }
        
        return -1;
    }
};
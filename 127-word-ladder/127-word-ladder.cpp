class Solution {
public:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> visited;
    
    void addNeighbors(set<string>& dict, string word) { 
        for (int i = 0; i < word.length(); i++) {
            char og = word[i]; 
            for (int j = 'a'; j <= 'z'; j++) {
                string temp = word;
                temp[i] = j;
                if (temp != word && dict.find(temp) != dict.end()) {
                    graph[word].push_back(temp);
                }                
            }
            word[i] = og;
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }
        
        set<string> dict;
        for (string& w : wordList) {
            dict.insert(w);
            visited[w] = false;
        }
        
        // Create Graph
        for (string word : wordList) {
            addNeighbors(dict, word);
        }
        
        queue<pair<string, int>> q;
        q.push({ beginWord, 0 });
        
        while (!q.empty()) {
            pair<string, int> curr = q.front();
            auto [w,d] = curr;
            q.pop();
            
            if (w == endWord) return d+1;
            
            visited[w] = true;
            for (string n : graph[w]) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push({ n, d+1 });
                }
            }
        }
        
        return 0;
    }
};

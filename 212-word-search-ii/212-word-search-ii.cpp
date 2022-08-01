class Solution {
public:
    vector<string> ans;
    vector<pair<int,int>> moves = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    
    bool isValid(vector<vector<char>>& board, int x, int y) {
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
        return false;
    }
    
    struct TrieNode {
        char ch;
        int wordCount;
        int wordEnd;
        TrieNode* adj[26];
        
        TrieNode(char c) {
            ch = c;
            wordCount = 0;
            wordEnd = 0;
            for (int i = 0; i < 26; i++) adj[i] = nullptr;
        }
    };
    
    void buildTrie(string& word, TrieNode* root) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!curr->adj[idx]) curr->adj[idx] = new TrieNode(word[i]);
            curr = curr->adj[idx];
            curr->wordCount += 1;
            // cout << curr->ch << ",";
        }
        curr->wordEnd += 1;
        // cout << endl;
    }
    
    void dfs(vector<vector<char>>& board, TrieNode* root, string str, int x, int y, vector<vector<bool>>& visited) {
        TrieNode* curr = root;
        char c = board[x][y];
        if (!curr || !curr->adj[c - 'a']) return;
        
        curr = curr->adj[c - 'a'];
        if (curr->wordEnd > 0) {
            ans.push_back(str + board[x][y]);
            curr->wordEnd = 0;
        }
        
        visited[x][y] = true;
        for (pair<int,int>& move : moves) {
            auto [dx, dy] = move;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(board, newX, newY) && !visited[newX][newY]) {
                dfs(board, curr, str + c, newX, newY, visited);
            }
        }
        visited[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        TrieNode* root = new TrieNode('#');
        for (string& word : words) buildTrie(word, root);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                dfs(board, root, "", i, j, visited);
            }
        }
        // dfs(board, root, "", 0, 0);
        
        return ans;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<pair<int,int>> moves = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    
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
    
    TrieNode* root;
    
    bool isValid(vector<vector<char>>& board, int x, int y) {
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
        return false;
    }
    
    void buildTrie(string& word, TrieNode* root) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!curr->adj[idx]) curr->adj[idx] = new TrieNode(word[i]);
            curr = curr->adj[idx];
            curr->wordCount += 1;
        }
        curr->wordEnd += 1;
    }
    
    void deleteWord(string word) {
        //cout << "Deleting : " << word << endl;
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            //cout << curr->ch << " ";
            curr = curr->adj[idx];
            curr->wordCount -= 1;
        }
        //cout << endl;
        curr->wordEnd -= 1;
    }
    
    void dfs(vector<vector<char>>& board, TrieNode* root, string str, int x, int y, vector<vector<bool>>& visited) {
        char c = board[x][y];
        TrieNode* curr = root->adj[c - 'a'];
        if (!curr || curr->wordCount == 0) return;
        
        //curr = curr->adj[c - 'a'];
        if (curr->wordEnd > 0) {
            ans.push_back(str + board[x][y]);
            curr->wordEnd -= 1;
            deleteWord(str + board[x][y]);
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
        root = new TrieNode('#');
        for (string& word : words) buildTrie(word, root);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                dfs(board, root, "", i, j, visited);
            }
        }
        
        return ans;
    }
};

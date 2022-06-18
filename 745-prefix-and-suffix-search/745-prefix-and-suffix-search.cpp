class WordFilter {
public:
    struct TrieNode {
        char ch;
        int pos;
        vector<TrieNode*> next;
        
        TrieNode(char c) {
            ch = c;
            pos = -1;
            next = vector<TrieNode*>(27, nullptr);
        }
    };
    
    void insert(TrieNode* root, string& word, int p) {
        // cout << word << " : " << p << endl;
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!curr->next[idx]) {
                curr->next[idx] = new TrieNode(word[i]);
            }
            curr = curr->next[idx];
            // cout << idx << " : " << curr->ch << endl;
        }
        curr->pos = p;
    }
    
    TrieNode* root;
    
    WordFilter(vector<string>& words) {
        root = new TrieNode('#');
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j <= word.length(); j++) {
                string str = word.substr(word.length()-j, j) + "{" + word;
                // cout << str << endl;
                insert(root, str, i);
            }
        }
    }
    
    TrieNode* find(TrieNode* root, string& str) {
        // cout << str << endl;
        TrieNode* curr = root;
        for (int i = 0; i < str.length(); i++) {
            int idx = str[i] - 'a';
            // cout << idx << " : " << curr->ch << endl;
            if (!curr->next[idx]) return nullptr;
            curr = curr->next[idx];            
        }
        return curr;
    }
    
    int findMax(TrieNode* root) {
        if (!root) return -1;
        // cout << root->ch << " : " << root->pos << endl;
        int ans = root->pos;
        for (int i = 0; i < 27; i++) {
            ans = max(ans, findMax(root->next[i]));
        }
        return ans;
    }
    
    int f(string prefix, string suffix) {
        string str = suffix + "{" + prefix;
        // cout << str << endl;
        TrieNode* n = find(root, str);
        if (!n) return -1;
        return findMax(n);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

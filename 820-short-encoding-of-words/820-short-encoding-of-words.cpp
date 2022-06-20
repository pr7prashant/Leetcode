class Solution {
public:
    struct TrieNode {
        char ch;
        int wordCount;
        vector<TrieNode*> next;
        
        TrieNode(char c) {
            ch = c;
            wordCount = 0;
            next = vector<TrieNode*>(26, nullptr);
        }
    };
    
    int insert(TrieNode* root, string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->next[idx]) curr->next[idx] = new TrieNode(ch);
            curr = curr->next[idx];
            curr->wordCount += 1;
            cout << ch << " : " << "idx : " << idx << " : " << curr->wordCount << endl;
        }
        return curr->wordCount;
    }
    
    TrieNode* root;
    
    Solution() {
        root = new TrieNode('$');
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.length() > b.length();
        });
        
        int ans = 0;
        for (string& word : words) {
            reverse(word.begin(), word.end());
            int wordCount = insert(root, word);
            cout << word << " : " << wordCount << endl;
            if (wordCount == 1) ans += word.length() + 1;
        }
        
        return ans;
    }
};

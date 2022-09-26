class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    Solution() {
        parent = vector<int>(26);
        rank = vector<int>(26, 0);
        for (int i = 0; i < 26; i++) parent[i] = i;
    }
    
    int getParent(int i) {
        if (parent[i] == i) return i;
        return getParent(parent[i]);
    }
    
    void unionn(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (rank[a] >= rank[b]) {
            parent[b] = a;
            rank[a]++;
        } else {
            parent[a] = b;
            rank[b]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        for (string& eq : equations) {
            char a = eq[0] - 'a', b = eq[3] - 'a';
            if (eq[1] == '=') unionn(a, b);
        }
        for (string& eq : equations) {
            char a = eq[0] - 'a', b = eq[3] - 'a';
            if (eq[1] == '!' && getParent(a) == getParent(b)) return false;
        }
        return true;
    }
};
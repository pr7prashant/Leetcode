class RandomizedSet {
private:
    vector<int> rset;
    unordered_map<int,int> mp;
    
public:
    RandomizedSet() {}
    
    void print() {
        for (int n : rset) cout << n << " , ";
        cout << endl;
    }
    
    bool insert(int val) {
        // cout << "Add " << val << endl;
        if (mp.find(val) != mp.end()) return false;
        rset.push_back(val);
        mp[val] = rset.size() - 1;
        // print();
        return true;
    }
    
    bool remove(int val) {
        // cout << "Remove " << val << endl;
        if (mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        mp[rset.back()] = idx;
        rset[idx] = rset.back();
        rset.pop_back();
        mp.erase(val);
        // print();
        return true;
    }
    
    int getRandom() {
        // cout << "Get Random " << endl;
        return rset[rand() % rset.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RandomizedSet {
private:
    vector<int> rset;
    unordered_map<int,int> mp;
    
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        rset.push_back(val);
        mp[val] = rset.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        mp[rset.back()] = idx;
        rset[idx] = rset.back();
        rset.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
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

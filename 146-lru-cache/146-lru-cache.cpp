class LRUCache {
public:
    int cap;
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        
        lru.emplace_front(key, mp[key]->second);
        lru.erase(mp[key]);
        mp[key] = lru.begin();
        
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            mp[key]->second = value;
            return;
        }
        
        if (lru.size() == cap) {
            int key = lru.back().first;
            mp.erase(key);
            lru.pop_back();
        }
        
        lru.emplace_front(key,value);
        mp[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
public:
    int cap;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;
    std::list<std::pair<int, int>> l;

    LRUCache(int capacity) : cap(capacity), mp(), l() {}
    
    int get(int key) {
        if (!mp.contains(key)) return -1;
        l.splice(l.begin(), l, mp[key]);
        return l.front().second;
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            l.splice(l.begin(), l, mp[key]);
            l.front().second = value;
            return;
        }

        if (l.size() == cap) {
            mp.erase(l.back().first);
            l.pop_back();
        }
        l.push_front({key, value});
        mp[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class RandomizedSet {
private:
    std::unordered_map<int, int> mp;
    std::vector<int> random;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.contains(val)) return false;
            
        random.push_back(val);
        mp[val] = random.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!mp.contains(val)) return false;

        int i = mp[val];
        random[i] = random.back();
        mp[random[i]] = i;

        mp.erase(val);
        random.pop_back();
        return true;
    }
    
    int getRandom() {
        return random[std::rand() % random.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

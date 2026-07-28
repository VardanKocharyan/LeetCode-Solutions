class TimeMap {
private:
    std::unordered_map<
                    std::string,
                    std::vector<std::pair<int, std::string>>
                    > mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.contains(key)) return "";

        auto it = std::upper_bound(
                            mp[key].begin(),
                            mp[key].end(),
                            timestamp,
                            [](int t, std::pair<int, std::string>& v) {
                                return t < v.first;
                            }
                    );
        if (it == mp[key].begin()) return "";
        
        return std::prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

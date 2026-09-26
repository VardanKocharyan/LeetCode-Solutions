class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::unordered_map<std::string, std::string> mp;
        std::string ans;
        
        for (std::vector<std::string>& v : knowledge) mp.insert({v[0], v[1]});

        for (size_t i{}; i < s.length(); ++i) {
            if (s[i] != '(') {
                ans.push_back(s[i]);
            } else {
                ++i;
                size_t pos{i};
                while (s[pos] != ')') ++pos;
                std::string key(s.substr(i, pos - i));
                ans += (mp.contains(key)) ? mp[key] : "?";
                i = pos;
            }
        }

        return ans;
    }
};

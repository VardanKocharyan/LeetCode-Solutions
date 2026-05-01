class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::stringstream ss(s);
        std::vector<std::string> value(26);

        for (int i{}; i < pattern.length(); ++i) {
            std::string word;
            ss >> word;
            int key = pattern[i] - 'a';
            if (value[key].empty()) value[key] = word;
            else if (value[key] != word) return false;
            
            for (int j{}; j < i; ++j) 
            {
                int k = pattern[j] - 'a';
                if ((word == value[k] && key != k) || word.empty()) return false;
            }
        }
        return ss.eof();
    }
};

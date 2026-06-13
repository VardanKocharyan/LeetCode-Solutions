class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        std::string res;
        
        for (const std::string& s : words) {
            int sum{};
            for (const char ch : s) {
                sum += weights[ch - 'a'];
            }
            res.push_back('z' - sum % 26);
        }
        
        return res;
    }
};

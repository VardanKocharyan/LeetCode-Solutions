class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::vector<int> ss(256, -1);
        std::vector<int> tt(256, -1);
        int n = s.length();
        for (int i{}; i < n; ++i) 
        {
            if (ss[s[i]] != tt[t[i]]) return false;
            ss[s[i]] = i;
            tt[t[i]] = i;
        }
        return true;
    }
};

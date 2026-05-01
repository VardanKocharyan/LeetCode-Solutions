class Solution {
public:
    char findTheDifference(string s, string t) {
        std::vector<int> ch(26, 0);
        for (int i{}; i < s.length(); ++i) ++ch[s[i] - 'a'];
        for (int i{}; i < t.length(); ++i) --ch[t[i] - 'a'];

        for (int i{}; i < 26; ++i)  
        {
            if (ch[i] != 0) return i + 'a';
        }
        return '\0';
    }
};

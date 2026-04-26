class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> anagram(26, 0);

        for (int i{}; i < s.length(); ++i) {
            ++anagram[s[i] - 'a'];
        }

        for (int i{}; i < t.length(); ++i) {
            --anagram[t[i] - 'a'];
        }

        for (int i{}; i < 26; ++i) {
            if (anagram[i]) return false;
        }

        return true;
    }
};

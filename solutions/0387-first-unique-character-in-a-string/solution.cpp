class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> count(26, 0);
        
        for (int i{}; i < s.length(); ++i) {
            ++count[s[i] - 'a'];
        }

        for (int i{}; i < s.length(); ++i) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int scoreOfParentheses(string s) {
        int32_t res{};
        int32_t open{};
        for (size_t i{}; i < s.length(); ++i) {
            if (s[i] == '(') ++open;
            else {
                --open;
                if (s[i - 1] == '(') res += (1 << open);
            }
        }
        return res;
    }
};

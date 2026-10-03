class Solution {
public:
    int longestValidParentheses(string s) {
        int32_t max{};

        for (size_t i{}; i < s.length(); ++i) {
            if (max > s.length() - i) break;
            else if (s[i] == ')') continue;
            else {
                int32_t open{};
                int32_t count{};
                for (size_t j{i}; j < s.length() && open >= 0; ++j) {
                    if (s[j] == '(') ++open;
                    else if ( (--open) >= 0) {
                        count += 2;
                        if (open == 0) max = std::max(max, count);
                    }
                }

            }
        }
        return max;
    }
};

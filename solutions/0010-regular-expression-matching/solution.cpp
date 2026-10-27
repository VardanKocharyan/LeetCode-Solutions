class Solution {
public:
    bool solve(int i, int j, std::string_view s, std::string_view p, std::vector<std::vector<int8_t>>& dp) {
        if (j == p.length()) return i == s.length();
        if (dp[i][j] != -1) return dp[i][j];

        if (j + 1 < p.length() && p[j + 1] == '*') {
            dp[i][j] = solve(i, j + 2, s, p, dp) ||
                        (i < s.length() && (p[j] == '.' || s[i] == p[j])) && solve(i + 1, j, s, p, dp);
        } else {
            dp[i][j] = (i < s.length() && (p[j] == '.' || s[i] == p[j])) && solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        std::vector<std::vector<int8_t>> dp(s.length() + 1, std::vector<int8_t>(p.length() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};

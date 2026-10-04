class Solution {
public:
    bool solve(size_t i, int32_t open, std::string_view s, std::vector<std::vector<int8_t>>& dp) {
        if (open < 0 || open > s.length() / 2) return 0;
        if (i == s.length()) return !open;
        if (dp[i][open] != -1) return dp[i][open];

        switch(s[i]) {
            case '(':
                dp[i][open] = solve(i + 1, open + 1, s, dp);
                break;

            case ')':
                dp[i][open] = solve(i + 1, open - 1, s, dp);
                break;

            default:
                dp[i][open] = 
                    solve(i + 1, open + 1, s, dp) ||
                    solve(i + 1, open - 1, s, dp) ||
                    solve(i + 1, open, s, dp);
        }

        return dp[i][open];
    }

    bool checkValidString(string s) {
        std::vector<std::vector<int8_t>> dp(s.length(), std::vector<int8_t>(s.length() / 2 + 1, -1));

        return solve(0, 0, s, dp);
        
    }
};

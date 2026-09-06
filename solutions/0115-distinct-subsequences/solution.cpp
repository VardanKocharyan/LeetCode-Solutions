class Solution {
public:
    int solve(int s_idx, int t_idx, std::string& s, std::string& t, std::vector<std::vector<int>>& dp) {
        if (t_idx >= t.length()) return 1;
        if (s_idx >= s.length()) return 0;
        if (dp[t_idx][s_idx] != -1) return dp[t_idx][s_idx];

        return dp[t_idx][s_idx] = solve(s_idx + 1, t_idx, s, t, dp) + ((s[s_idx] == t[t_idx]) ? solve(s_idx + 1, t_idx + 1, s, t, dp) : 0);
    }

    int numDistinct(string s, string t) {
        std::vector<std::vector<int>> dp(t.length(), std::vector<int>(s.length(), -1));

        return solve(0, 0, s, t, dp);
    }
};

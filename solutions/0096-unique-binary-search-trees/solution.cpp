class Solution {
public:
    int32_t solve(int n, std::vector<int32_t>& dp) {
        if (!n || n == 1) return 1;
        if (dp[n]) return dp[n];

        for (int i{1}; i <= n; ++i) {
            int32_t left = solve(i - 1, dp);
            int32_t right = solve(n - i, dp);
            dp[n] += left * right;
        }

        return dp[n];
    }

    int numTrees(int n) {
        if (n == 1) return 1;
        std::vector<int32_t> dp(n + 1, 0);

        return solve(n, dp);
    }
};


class Solution {
public:
    int32_t solve(int x, int n, std::vector<int32_t>& dp) {
        if (n < 4) return n;
        // if (n < 0) return 1e5;
        if (dp[n] != 1e5) return dp[n];

        for (int i{x}; i >= 1; --i) {
            if (n < i * i) continue;
            dp[n] = std::min(dp[n], solve(x, n - (i * i), dp) + 1);
        }

        return dp[n];
    }

    int numSquares(int n) {
        std::vector<int32_t> dp(n + 1, 1e5);
        int x = static_cast<int>(std::sqrt(n));

        return solve(x, n, dp);
    }
};

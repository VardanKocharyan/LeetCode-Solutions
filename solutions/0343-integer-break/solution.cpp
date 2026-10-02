class Solution {
public:
    int32_t dfs(int32_t n, std::vector<int32_t>& dp) {
        if (n == 0) return 1;
        if (dp[n]) return dp[n];

        int32_t max_product{};
        for (int i{1}; i <= n; ++i) {
            dp[n - i] = dfs(n - i, dp);
            max_product = std::max( max_product, i * std::max(dp[n - i], (n - i)) );
        }
        return dp[n] = max_product;
    }

    int integerBreak(int n) {
        std::vector<int32_t> dp(n + 1);
        dp[1] = 1;
        dp[2] = 1;
        if (n >= 3) dp[3] = 2;

        return dfs(n, dp);
    }
};

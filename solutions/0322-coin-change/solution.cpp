class Solution {
public:
    int solve(int i, int amount, std::vector<int>& c, std::vector<std::vector<int>>& dp) {
        if (i == 0) return dp[0][amount] = amount % c[0] == 0 ? amount / c[0] : std::numeric_limits<int>::max();
        if (dp[i][amount] != -1) return dp[i][amount];

        int take = std::numeric_limits<int>::max();
        if (amount >= c[i]) {
            int res = solve(i, amount - c[i], c, dp);

            if (res != std::numeric_limits<int>::max()) take = 1 + res;
        }

        int not_take = solve(i - 1, amount, c, dp);

        return dp[i][amount] = std::min(take, not_take);

    }

    int coinChange(vector<int>& coins, int amount) {
        std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount + 1, -1));

        int res = solve(coins.size() - 1, amount, coins, dp);
    
        return res != std::numeric_limits<int>::max() ? res : -1;
    }
};

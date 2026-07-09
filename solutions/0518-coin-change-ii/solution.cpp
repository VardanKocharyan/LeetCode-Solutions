class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (const int c : coins) {
             for (int sum{c}; sum <= amount; ++sum) {
                dp[sum] += dp[sum - c];
             }
        }
        return dp[amount];
    }
};

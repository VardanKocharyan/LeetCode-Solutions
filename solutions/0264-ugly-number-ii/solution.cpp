class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> dp(n, 1);
        int i{}, j{}, k{};
        
        for (int step{1}; step < n; ++step) {
            int min = std::min({dp[i] * 2, dp[j] * 3, dp[k] * 5});

            if (min == dp[i] * 2) ++i;
            if (min == dp[j] * 3) ++j;
            if (min == dp[k] * 5) ++k;

            dp[step] = min;
        }
        return dp.back();
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n, 1);
        while (--m) { //we do --m or not m-- , because we have 1st line
            for (int i{1}; i < n; ++i) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};

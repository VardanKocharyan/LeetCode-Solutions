class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<int> dp(m, 1e9);
        
        dp = grid[0];

        for (int day{1}; day < n; ++day) {
            std::vector<int> curr(m);
            for (int task{}; task < m; ++task) {
                int best = std::numeric_limits<int>::max();
                for (int prev{}; prev < m; ++prev) {
                    if (prev ^ task) {
                        best = std::min(best, dp[prev]);
                    }
                }
                curr[task] = best + grid[day][task];
            }
            dp = std::move(curr);
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};

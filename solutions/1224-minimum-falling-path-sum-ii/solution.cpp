class Solution {
public:
    int solve(int day, int l_task, std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& g) {
        if (dp[day][l_task] != 1e9) return dp[day][l_task];
        int res = std::numeric_limits<int>::max();
        if (day == 0) {
            for (int task{}; task < g[0].size(); ++task) {
                if (task ^ l_task) {
                    res = std::min(res, g[day][task]);
                }
            }
            return dp[day][l_task] = res;
        }

        for (int task{}; task < g[0].size(); ++task) {
            if (task ^ l_task) {
                res = std::min(res, solve(day - 1, task, dp, g) + g[day][task]);
            }
        }
        return dp[day][l_task] = res;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1, 1e9));
        return solve(n - 1, m, dp, grid);
    }
};

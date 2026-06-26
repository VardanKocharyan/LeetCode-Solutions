class Solution {
public:
    int solve(int i, int j, std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& grid) {
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if (!i && !j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j - 1, dp, grid);
        int up = solve(i - 1, j, dp, grid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) return 0;
    
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));

        return solve(n - 1, m - 1, dp, obstacleGrid);
    }
};

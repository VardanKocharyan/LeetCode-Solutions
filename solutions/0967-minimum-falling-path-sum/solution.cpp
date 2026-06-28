class Solution {
public:
    int solve(int i, int j, std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& matrix) {
        if (j < 0 || j >= matrix[0].size()) return 1e9;
        if (i == 0) return matrix[i][j];
        if (dp[i][j] != 1e9) return dp[i][j];

        int up = solve(i - 1, j, dp, matrix);
        int dl = solve(i - 1, j - 1, dp, matrix);
        int dr = solve(i - 1, j + 1, dp, matrix);

        return dp[i][j] = matrix[i][j] + std::min({up, dl, dr});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 1e9));

        int res = 1e9;
        for (int i{}; i < n; ++i) {
            res = std::min(res, solve(n - 1, i, dp, matrix)); 
        }

        return res;
    }
};

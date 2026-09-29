class Solution {
public:
    bool solve(int i, int j, int count, std::vector<std::vector<char>>& grid, std::vector<std::vector<std::vector<int8_t>>>& dp) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        
        if (i == n || j == m) return false;

        count += (grid[i][j] == '(') ? 1 : -1;

        if (count < 0 || count > (n + m) / 2) return false;
        if (i == n - 1 && j == m - 1) return count == 0;
        if (dp[i][j][count] != -1) return dp[i][j][count];

        bool down   = solve(i + 1, j, count, grid, dp);
        bool right  = solve(i, j + 1, count, grid, dp);
        
        return dp[i][j][count] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        if ( ((n + m - 1) & 1) || grid[n - 1][m - 1] == '(' || grid[0][0] == ')') return false;
        std::vector<std::vector<std::vector<int8_t>>> dp(n, std::vector(m, std::vector<int8_t>((n + m) / 2 + 1, -1)));
        
        return solve(0, 0, 0, grid, dp);
    }
};

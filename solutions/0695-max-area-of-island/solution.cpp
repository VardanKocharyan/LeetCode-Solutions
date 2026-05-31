class Solution {
public:
    int dfs(int i, int j, std::vector<std::vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 0) return 0;

        g[i][j] = 0;

        return 1 + dfs(i + 1, j, g) +
                dfs(i - 1, j, g) +
                dfs(i, j + 1, g) +
                dfs(i, j - 1, g);
    } 

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxilend{};

        for (int i{}; i < r; ++i) {
            for (int j{}; j < c; ++j) {
                maxilend = std::max(maxilend, dfs(i, j, grid));
            }
        }
        return maxilend;
    }
};

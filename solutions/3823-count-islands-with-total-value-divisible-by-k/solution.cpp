class Solution {
public:
    long long dfs(int i, int j, int n, int m , std::vector<std::vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || !grid[i][j]) return 0;
        long long sum = grid[i][j];
        grid[i][j] = 0;
        return sum += 
            dfs(i + 1, j, n, m, grid) + 
            dfs(i, j - 1, n, m, grid) + 
            dfs(i - 1, j, n, m, grid) + 
            dfs(i, j + 1, n, m, grid);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());

        int ans{};
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (grid[i][j] && !(dfs(i, j, n, m, grid) % k)) ++ans;
            }
        }
        return ans;
    }
};

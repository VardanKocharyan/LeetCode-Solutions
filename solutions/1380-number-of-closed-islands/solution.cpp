class Solution {
public:
    bool dfs(int i, int j, int n, int m, std::vector<std::vector<int>>& grid, std::vector<std::vector<int8_t>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m) return 0;
        if (visited[i][j] != -1) return visited[i][j];
        if (grid[i][j] == 1) return 1;

        std::vector<int> dr({1, 0, -1, 0, 1});
        visited[i][j] = 1;
        
        return visited[i][j] = 
            dfs(i + dr[0], j + dr[1], n, m, grid, visited) &&
            dfs(i + dr[1], j + dr[2], n, m, grid, visited) &&
            dfs(i + dr[2], j + dr[3], n, m, grid, visited) &&
            dfs(i + dr[3], j + dr[4], n, m, grid, visited);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());
        std::vector<std::vector<int8_t>> visited(n, std::vector<int8_t>(m, -1));

        int ans{};
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (
                    grid[i][j] == 0 && 
                    visited[i][j] == -1 && 
                    dfs(i, j, n, m, grid, visited)
                ) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

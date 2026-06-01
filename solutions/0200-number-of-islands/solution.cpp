class Solution {
private:
    int count{};

public:
    void dfs(int i, int j, std::vector<std::vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '0') return;

        g[i][j] = '0';

        dfs(i + 1, j, g);
        dfs(i - 1, j, g);
        dfs(i, j + 1, g);
        dfs(i, j - 1, g);
    } 

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ++count;
                }
            }
        }

        return count;
    }
};

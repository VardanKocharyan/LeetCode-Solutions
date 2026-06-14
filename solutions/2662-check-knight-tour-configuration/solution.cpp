class Solution {
public:
    bool isValid(int i, int j, int n, int target, std::vector<std::vector<int>>& grid) {
        return ((i >=0 && i < n) && (j >=0 && j < n)) && (target + 1 == grid[i][j]);
    }

    bool ValidGrid(int i, int j, std::vector<std::pair<int, int>>& step, std::vector<std::vector<int>>& grid) {
        if (grid[i][j] == grid.size() * grid[0].size() - 1) return true;

        for (const auto& [n_i, n_j] : step) {
            if (isValid(i + n_i, j + n_j, grid.size(), grid[i][j], grid) && ValidGrid(i + n_i, j + n_j, step, grid)) return true;
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid.size() < 5 || grid[0][0]) return false;
        std::vector<std::pair<int, int>> step({{-2, 1}, 
                                                {-2, -1},
                                                {-1, -2},
                                                {-1, 2},
                                                {2, 1},
                                                {2, -1},
                                                {1, 2},
                                                {1, -2}}
                                                );
        return ValidGrid(0, 0, step, grid);
    }
};

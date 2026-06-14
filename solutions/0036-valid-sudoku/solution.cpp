class Solution {
public:
    bool isValid(std::vector<std::vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '.') return true;
        
        for (int k{j + 1}; k < 9; ++k) {
            if (grid[i][k] == grid[i][j]) return false;
        }

        for (int k{i + 1}; k < 9; ++k) {
            if (grid[k][j] == grid[i][j]) return false;
        }

        int row = i - i % 3 + 3;
        int col = j - j % 3 + 3;
        for (int k = i - i % 3; k < row; ++k) {
            for (int q = j - j % 3; q < col; ++q) {
                if ((k != i && q != j) && grid[k][q] == grid[i][j]) return false;
            }
        }
        return true;
    }

    bool sudoku(std::vector<std::vector<char>>& grid, int i, int j) {
        if (i == 8 && j == 9) return true;
        if (j == 9) {
            ++i;
            j = 0;
        }

        if (isValid(grid, i, j) && sudoku(grid, i, j + 1)) return true;

        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return sudoku(board, 0, 0);
    }
};

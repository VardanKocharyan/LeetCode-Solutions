class Solution {
public:
    bool isValid(std::vector<std::vector<char>>& grid, int i, int j) {
        for (int k{}; k < 9; ++k) {
            if (grid[i][k] == grid[i][j] && k != j) return false;
        }

        for (int k{}; k < 9; ++k) {
            if (grid[k][j] == grid[i][j] && k != i) return false;
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
            j = 0;
            ++i;
        }

        if (grid[i][j] != '.') {
            if (sudoku(grid, i, j + 1)) return true;
        } else { 
            for (int k{1}; k < 10; ++k) {
                grid[i][j] = '0' + k;
                if (isValid(grid, i, j) && sudoku(grid, i, j + 1)) return true;
                grid[i][j] = '.';
            }
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool res = sudoku(board, 0, 0);
    }
};

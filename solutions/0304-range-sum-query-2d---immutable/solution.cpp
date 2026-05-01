class NumMatrix {
public:
    std::vector<std::vector<int>> M;
    NumMatrix(vector<vector<int>>& matrix) 
    : M(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i{}; i < row; ++i) {
            for (int j{}; j < col; ++j) {
                M[i + 1][j + 1] = matrix[i][j] + M[i + 1][j] + M[i][j + 1] - M[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return M[row2 + 1][col2 + 1] - M[row2 + 1][col1] - M[row1][col2 + 1] + M[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

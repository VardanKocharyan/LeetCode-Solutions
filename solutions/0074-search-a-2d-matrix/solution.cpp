class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int l{}, r = (row * col) - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (matrix[m / col][m % col] < target) l = m + 1;
        else if (matrix[m / col][m % col] > target) r = m - 1;
        else return true;  
    }

    return false;

    }
};

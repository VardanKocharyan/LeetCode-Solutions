class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row{}, col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            
            int digit = matrix[row][col];
            
            if (digit == target) return true;
            else if (digit < target) {
                ++row;
            } else {
                --col;
            }
        }
        return false;
    }
};

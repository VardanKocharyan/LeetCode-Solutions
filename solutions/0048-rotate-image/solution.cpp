class Solution {
public:
    void rotate_line(std::vector<int>& nums) {
        int last = nums.size() - 1;
        int first = 0;

        while (first < last) {
            std::swap(nums[first++], nums[last--]);
        }
    }

    void transpose(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for(int i{}; i < n; ++i) {
            
            int j = i + 1;

            while (j < n) {
                std::swap(matrix[i][j], matrix[j][i]);
                ++j;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        
        transpose(matrix);

        for (int i{}; i < matrix.size(); ++i) {
            rotate_line(matrix[i]);
        }
    }
};

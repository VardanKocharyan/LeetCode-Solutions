class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftSum(n + 1, 0);
        std::vector<int> rightSum(n + 1, 0);
        std::vector<int> res(n);

        for (int i{0}; i < n; ++i) {
            leftSum[i + 1] = leftSum[i] + nums[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            rightSum[i] = rightSum[i + 1] + nums[i];
        }

        for (int i{}; i < n; ++i) {
            res[i] = std::abs(leftSum[i] - rightSum[i + 1]);
        }

        return res;
    }
};

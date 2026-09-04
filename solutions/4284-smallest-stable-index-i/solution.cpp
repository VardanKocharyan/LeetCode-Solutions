class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> min(n);

        min.back() = nums.back();
        int max = nums.front();

        for (int i{n - 2}; i >= 0; --i) {
            min[i] = std::min(nums[i], min[i + 1]);
        }

        for (int i{}; i < n; ++i) {
            max = std::max(max, nums[i]);
            if (max - min[i] <= k) return i;
        }

        return -1;
    }
};

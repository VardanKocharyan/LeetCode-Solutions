class Solution {
public:
    struct MinMaxProduct {
        int max{};
        int min{};
    };

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        std::vector<MinMaxProduct> dp(n);
        dp.back().max = nums.back();
        dp.back().min = nums.back();

        for (int i{n - 2}; i >= 0; --i) {
            dp[i].max = std::max({nums[i], nums[i] * nums[i + 1], nums[i] * dp[i + 1].max, nums[i] * dp[i + 1].min});
            dp[i].min = std::min({nums[i], nums[i] * nums[i + 1], nums[i] * dp[i + 1].max, nums[i] * dp[i + 1].min});
        }

        return (*std::max_element(dp.begin(), dp.end(), [](const MinMaxProduct& a, const MinMaxProduct& b) {
            return a.max < b.max;
        })).max;
    }
};

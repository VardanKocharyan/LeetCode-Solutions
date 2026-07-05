class Solution {
public:
    int solve(int i, int t, std::vector<std::vector<int>>& dp, std::vector<int>& nums) {
        if (!i) {
            if (!t && !nums[i]) return 2;
            if (!t || t == nums[i]) return 1;
            return 0;
        }
        if (dp[i][t] != -1) return dp[i][t];

        return dp[i][t] = solve(i - 1, t, dp, nums) + (t >= nums[i] ? solve(i - 1, t - nums[i], dp, nums) : 0);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int m = (total - target) / 2;

        if ((total - target) < 0 || (total - target) & 1) return 0;

        std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1, -1));

        return solve(n - 1, m, dp, nums);
    }
};

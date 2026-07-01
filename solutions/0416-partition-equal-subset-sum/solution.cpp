class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum{};
        
        for (const int num : nums) sum += num;

        if (sum & 1) return false;

        int target = sum / 2;
        std::vector<bool> dp(target + 1);

        dp[0] = true;

        for (const int num : nums) {
            for (int sum{target}; sum - num >= 0; --sum) {
                dp[sum] = dp[sum] || dp[sum - num];
            }
        }
        return dp[target];
    }
};

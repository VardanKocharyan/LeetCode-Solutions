class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = std::numeric_limits<int>::max();
        int l{};
        int sum{};

        for (int r{}; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                min = std::min(min, r - l + 1);

                sum -= nums[l++];
            }
        }

        return min == std::numeric_limits<int>::max() ? 0 : min;
    }
};

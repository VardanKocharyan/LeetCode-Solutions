class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min{std::numeric_limits<int>::max()},
                  max{std::numeric_limits<int>::min()};
        
        for (int i{}; i < nums.size(); ++i) {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > max) max = nums[i];
        }

        long long res = k * (max - min);

        return res;
    }
};

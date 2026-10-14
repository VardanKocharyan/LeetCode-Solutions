class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int32_t up{};
        int32_t down{};

        for (size_t i{1}; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) up = down + 1;
            else if (nums[i] < nums[i - 1]) down = up + 1;
        }

        return std::max(up, down) + 1;
    }
};

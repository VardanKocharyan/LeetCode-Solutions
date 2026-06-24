class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.back();
        int p1{}, p2{};
        int idx1{}, idx2{};
        for (int i{}; i < nums.size() - 1; ++i) {
            int curr1 = std::max(nums[i] + p2, p1);
            int curr2 = std::max(nums[i + 1] + idx2, idx1);

            p2 = p1;
            p1 = curr1;

            idx2 = idx1;
            idx1 = curr2;
        }
        return std::max(idx1, p1);
    }
};

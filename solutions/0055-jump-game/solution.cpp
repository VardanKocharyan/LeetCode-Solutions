class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump{};
        for (int i{}; (i <= max_jump && max_jump < nums.size() - 1); ++i) {
            max_jump = std::max(max_jump, i + nums[i]);
        }

        return max_jump >= nums.size() - 1;
    }
};

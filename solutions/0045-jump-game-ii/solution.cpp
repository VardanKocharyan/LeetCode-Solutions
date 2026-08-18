class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int start{};
        int max_jump_idx{};
        int step{1};

        while (max_jump_idx + nums[max_jump_idx] < nums.size() - 1) {
            ++step;
            int new_max{};
            for (int i{start}; i <= max_jump_idx + nums[max_jump_idx]; ++i) {
                new_max = (new_max + nums[new_max] < i + nums[i]) ? i : new_max;
            }

            start = max_jump_idx + nums[max_jump_idx];
            max_jump_idx = new_max;
        }

        return step;
    }
};

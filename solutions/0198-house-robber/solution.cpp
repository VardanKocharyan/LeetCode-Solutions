class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() > 1) nums[1] = std::max(nums[0], nums[1]);
        for (int i{2}; i < nums.size(); ++i) 
            nums[i] = std::max(nums[i] + nums[i - 2], nums[i - 1]);
        return nums.back();
    }
};

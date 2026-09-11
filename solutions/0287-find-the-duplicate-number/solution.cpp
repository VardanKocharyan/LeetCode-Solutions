class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i{}; i < nums.size();) {
            if (i != nums[i] - 1 && nums[i] == nums[nums[i] - 1]) return nums[i];
            std::swap(nums[i], nums[nums[i] - 1]);
            if (nums[i] == i + 1) ++i;
        }
        return -1;
    }
};

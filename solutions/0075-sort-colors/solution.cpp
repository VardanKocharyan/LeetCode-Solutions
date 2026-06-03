class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int r = nums.size() - 1;

        while (m <= r) {
            if (nums[m] == 0) std::swap(nums[l++], nums[m++]);
            else if (nums[m] == 1) ++m;
            else std::swap(nums[m], nums[r--]);
        }
    }
};

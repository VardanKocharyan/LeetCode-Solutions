class Solution {
public:
    int findMin(vector<int>& nums) {
        int l{}, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[l] <= nums[m]) {
                if (nums[l] >= nums[r]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};

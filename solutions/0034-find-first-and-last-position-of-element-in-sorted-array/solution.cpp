class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        std::vector<int> res(2, -1);
        int l{}, r = nums.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int l1{}, r1 = nums.size();
        while (l1 < r1) {
            int m = l1 + (r1 - l1) / 2;
            if (nums[m] <= target) {
                l1 = m + 1;
            } else {
                r1 = m;
            }
        }
        if (l1 != l) {
            res[0] = l;
            res[1] = l1 - 1;
        } 
        return res;
    }
};

class Solution {
public:
    int bs(std::vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r  - l) / 2;
            if (nums[m] < target) l = m + 1;
            else if(nums[m] > target) r = m - 1;
            else return m; 
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l{}, r = nums.size() - 1;
        
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;

        if (nums[l] <= nums[r]) return bs(nums, l, r, target);


        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) return m;
            else if (nums[l] < nums[m]) {
                if (target >= nums[l] && target < nums[m]) return bs(nums, l, m, target);
                else {
                    l = m + 1;
                }
            } else {
                if (target >= nums[l] || nums[m] > target) {
                    r = m;
                } else {
                    l = m + 1;
                    return bs(nums, l, r, target);
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};

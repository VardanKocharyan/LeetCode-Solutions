class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left{}, right = nums.size() - 1, target = nums.size() - k;

        while (left <= right) {
            int l{left}, r{right}, j{left};
            int pivot = nums[l + (r - l) / 2];

            while (j <= r) {
                if (nums[j] < pivot) {
                    std::swap(nums[l++], nums[j++]);
                } else if (nums[j] > pivot) {
                    std::swap(nums[j], nums[r--]);
                } else {
                    ++j;
                }
            }

            if (l > target) right = l - 1;
            else if (r < target) left = r + 1;
            else return pivot;
        }
        return -1;
    }
};


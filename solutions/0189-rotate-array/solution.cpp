class Solution {
public:
    void rt(std::vector<int>& nums, int first, int last) {
        while (first < last) {
            std::swap(nums[first], nums[last]);
            ++first;
            --last;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int last = nums.size() - 1;
        int first = 0;
        k = k % nums.size();
        rt(nums, first, last);
        rt(nums, 0, k - 1);
        rt(nums, k, nums.size()-1);
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        std::vector<int> arr;
        for(size_t i{}; i < n; ++i) {
            arr.push_back(nums[i]);
            arr.push_back(nums[n + i]);
        }
        return arr;
    }
};

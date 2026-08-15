class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> res;
        for (int i{}; i < nums.size(); ++i) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return res.size();
    }
};

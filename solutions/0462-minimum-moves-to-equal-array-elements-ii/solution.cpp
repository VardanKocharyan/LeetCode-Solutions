class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        const int middle = nums[nums.size() / 2];
        return std::accumulate(nums.begin(), nums.end(), 0, [&](int acc, int nb) {
            return acc + std::abs(nb - middle);
        });
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0) - nums.size() * *std::min_element(nums.begin(), nums.end());
    }
};

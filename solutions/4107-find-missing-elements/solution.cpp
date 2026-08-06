class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::vector<int> res;
        std::vector<bool> visited(101, false);

        for (const int nb : nums) visited[nb] = true;

        auto [min, max] = std::minmax_element(nums.begin(), nums.end());
        for (int i{*min + 1}; i < *max; ++i) {
            if (!visited[i]) res.push_back(i);
        }

        return res;
    }
};

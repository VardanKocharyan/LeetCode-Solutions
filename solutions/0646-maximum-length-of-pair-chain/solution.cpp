class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int count{};
        int end = std::numeric_limits<int>::min();

        for (const std::vector<int>& pair : pairs) {
            if (pair[0] > end) {
                ++count;
                end = pair[1];
            }
        }
        return count;
    }
};

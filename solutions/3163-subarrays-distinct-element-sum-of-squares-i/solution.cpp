class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int n{static_cast<int>(nums.size())};
        int totalSum{0};

        for (int i{0}; i < n; ++i) {
            bool visited[101] = {false};
            int distinctCount{0};

            for (int j{i}; j < n; ++j) {
                const int val{nums[j]};

                if (!visited[val]) {
                    visited[val] = true;
                    ++distinctCount;
                }

                totalSum += distinctCount * distinctCount;
            }
        }

        return totalSum;
    }
};

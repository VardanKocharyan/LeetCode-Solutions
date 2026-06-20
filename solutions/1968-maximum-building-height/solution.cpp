class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) return n - 1;

        int max{};        
        restrictions.push_back({1, 0});
        std::sort(restrictions.begin(), restrictions.end());

        if (restrictions.back()[0] != n) restrictions.push_back({n, n - 1});

        for (int i{1}; i < restrictions.size(); ++i) {
            restrictions[i][1] = std::min(restrictions[i][1], (restrictions[i][0] - restrictions[i - 1][0]) + restrictions[i - 1][1]);
        }

        for (int i = restrictions.size() - 2; i >= 0; --i) {
            restrictions[i][1] = std::min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]) );
        }

        for (int i{0}; i < restrictions.size() - 1; ++i) {
            int curr = ((restrictions[i + 1][0] - restrictions[i][0]) + restrictions[i + 1][1] + restrictions[i][1]) / 2;
            max = std::max(max, curr);
        }

        return max;
    }
};

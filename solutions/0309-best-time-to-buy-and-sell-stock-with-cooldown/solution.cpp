class Solution {
public:
    int free(int i, std::vector<int>& p, std::vector<int>& fr, std::vector<std::vector<int>>& hold) {
        if (i >= p.size()) return 0;
        if (fr[i] != -1) return fr[i];

        return fr[i] = std::max(
            free(i + 1, p, fr, hold),
            holding(i, i + 1, p, fr, hold)
        );
    }

    int holding(int buy, int i, std::vector<int>& p, std::vector<int>& fr, std::vector<std::vector<int>>& hold) {
        if (i >= p.size()) return 0;
        if (hold[buy][i] != -1) return hold[buy][i];

        return hold[buy][i] = std::max(
            holding(buy, i + 1, p, fr, hold),
            (p[i] - p[buy]) + free(i + 2, p, fr, hold)
        );                
    }

    int maxProfit(vector<int>& prices) {
        std::vector<int> fr(prices.size(), -1);
        std::vector<std::vector<int>> hold(prices.size(), std::vector<int>(prices.size(), -1));

        return free(0, prices, fr, hold);
    }
};

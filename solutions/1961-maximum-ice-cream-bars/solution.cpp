class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n{};
        auto [min, max] = std::minmax_element(costs.begin(), costs.end());
        std::vector<int> count(*max - *min + 1, 0);

        for (const int nb : costs) ++count[nb - *min];

        for (int i{}; i < count.size(); ) {
            if (coins  < i + *min) return n;
            else if (count[i]--) {
                coins -= (i + *min);
                ++n;
            } else ++i;
        }
        
        return n;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j{0}, max{};
        for (int i{1}; i < prices.size(); ++i) {
            if (prices[i] < prices[j]) j = i;
            if (prices[i] - prices[j] > max && j != i) max = prices[i] - prices[j];
        }
        return max;
    }
};

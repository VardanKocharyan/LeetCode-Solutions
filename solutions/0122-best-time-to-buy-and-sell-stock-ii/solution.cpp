class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j{}, n = prices.size();
        int maxprice{}, max{}; 

        for (int i{1}; i < n; ++i) {
            if (prices[i] < prices[j]) {
                j = i;
                continue;
            } else {
                int carry = prices[i] - prices[j];
                if (max < carry) max = carry;

                if (i + 1 < n && prices[i] > prices[i + 1]) {
                    maxprice += max;
                    max = 0;

                    j = ++i;
                }
            }
        }
        if (max) maxprice += max;

        return maxprice;

    }
};

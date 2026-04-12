class Solution {
public:
    int cross(std::vector<int>& diff, int l, int r) {
        int max1{};
        int carry{};
        int m = l + (r - l) / 2;
                
        for (int i = m; i >= l; --i) {
            carry += diff[i];
            if (carry > max1) max1 = carry;
        }
        int max2{};
        carry = 0;

        for (int i = m + 1; i <= r; ++i) {
            carry += diff[i];
            if (carry > max2) max2 = carry;
        }
        return max1 + max2;
    }

    int devide_and_conqure(std::vector<int>& diff, int l, int r) {
        if (l >= r) return std::max(0, diff[l]);
        int m = l + (r - l) / 2;

        int left = devide_and_conqure(diff, l, m);
        int right = devide_and_conqure(diff, m + 1, r);
        int sum_cross = cross(diff, l, r);

        return std::max(left, std::max(right, sum_cross));
    }

    int maxProfit(vector<int>& prices) {

        if (prices.size() == 1) return 0;

        std::vector<int> diff(prices.size() - 1);
        for (int i{}; i < diff.size(); ++i) {
            diff[i] = prices[i + 1] - prices[i];
        }

        int l{}, r = diff.size() - 1;
        return devide_and_conqure(diff, l, r);
    }
};

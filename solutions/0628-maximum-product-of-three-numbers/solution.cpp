class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1{std::numeric_limits<int>::min()},
            max2{std::numeric_limits<int>::min()},
            max3{std::numeric_limits<int>::min()},
            min1{std::numeric_limits<int>::max()},
            min2{std::numeric_limits<int>::max()};

        for (const int nb : nums) {
            if (nb > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nb;
            } else if (nb > max2) {
                max3 = max2;
                max2 = nb;
            } else if (nb > max3) {
                max3 = nb;
            }

            if (min1 > nb) {
                min2 = min1;
                min1 = nb;
            } else if (min2 > nb) {
                min2 = nb;
            }
        }

        return std::max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

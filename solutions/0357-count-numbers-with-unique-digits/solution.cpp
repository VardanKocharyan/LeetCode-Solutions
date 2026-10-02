class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        int32_t total{10};
        int32_t product{9};

        for (int32_t i{9}; i > (10 - n); --i) {
            product *= i;
            total += product;
        }
        return total;
    }
};

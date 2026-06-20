class Solution {
public:
    int divide(int dividend, int divisor) {
        long long div = dividend, dev = divisor;
        if (div / dev > std::numeric_limits<int>::max()) return std::numeric_limits<int>::max();
        if (div / dev < std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();
        return div / dev;
    }
};

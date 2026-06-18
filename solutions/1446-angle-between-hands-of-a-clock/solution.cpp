class Solution {
public:
    double angleClock(int hour, int minutes) {
        double res = std::fabs(static_cast<double>(5.5 * minutes - 30 * hour));
        return std::min(360 - res, res);
    }
};

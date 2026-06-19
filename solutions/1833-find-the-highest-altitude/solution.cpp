class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max{}, curr{};
        for (const int nb : gain) {
            curr += nb;
            max = std::max(max, curr);
        }
        return max;
    }
};

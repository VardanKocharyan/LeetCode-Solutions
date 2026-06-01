class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        std::vector<int> count(101, 0);
        long long res{};

        for (int nb : cost) {
            ++count[nb];
        }

        int j{};
        for (int i = 100; i >= 0; --i) {
            while (count[i] > 0) {
                ++j;

                if (j % 3) res += i;

                --count[i];
            }
        }

        return res;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank{};
        int res{};

        int start{};
        for (int i{}; i < n; ++i) {
            gas[i] += -cost[i];
            res += gas[i];
            tank += gas[i];

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (res >= 0) ? start : -1;
    }
};

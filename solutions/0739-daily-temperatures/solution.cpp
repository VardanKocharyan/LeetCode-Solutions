class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::vector<int> helper;

        for (int i{}; i < temperatures.size(); ++i) {
            while (!helper.empty() && temperatures[helper.back()] < temperatures[i]) {
                res[helper.back()] = i - helper.back();
                helper.pop_back();
            }
            helper.push_back(i);
        }
        return res;
    }
};

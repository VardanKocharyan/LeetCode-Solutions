class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> paskal(numRows, std::vector<int>());
        paskal[0].push_back(1);

        for (int i{1}; i < numRows; ++i) {
            paskal[i].push_back(1);
            for (int j{1}; j < i; ++j) {
                paskal[i].push_back(paskal[i - 1][j - 1] + paskal[i - 1][j]);
            }
            paskal[i].push_back(1);
        }
        return paskal;
    }
};

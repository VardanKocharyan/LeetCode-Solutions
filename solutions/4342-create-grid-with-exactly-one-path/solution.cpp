class Solution {
public:
    vector<string> createGrid(int m, int n) {
        std::string s(n, '#');
        s.front() = '.';

        std::vector<std::string> ans(m - 1, s);
        ans.emplace_back(std::string(n, '.'));

        return ans;
    }
};

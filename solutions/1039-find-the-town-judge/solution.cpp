class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> indeg(n, 0);

        for (const std::vector<int> v : trust) {
            --indeg[v[0] - 1];
            ++indeg[v[1] - 1];
        }

        for (int i{}; i < n; ++i) {
            if (indeg[i] == n - 1) return i + 1;
        }
        return -1;
    }
};

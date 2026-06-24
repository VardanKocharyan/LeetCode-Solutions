class Solution {
public:
    void rec(int i, int n, int k, std::vector<int>& tmp, std::vector<std::vector<int>>& res) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        for (int step{i}; (step <= n && k - tmp.size() <= n - i + 1); ++step) {
            tmp.push_back(step);
            rec(step + 1, n, k, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;
        rec(1, n, k, tmp, res);
        return res;
    }
};

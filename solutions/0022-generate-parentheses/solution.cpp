class Solution {
private:
    std::vector<string> res;
public:
    void dfs(int o, int c, int n, std::string tmp) {
        if (c == n) {
            res.push_back(tmp);
            return;
        }

        if (o < n) {
            tmp.push_back('(');
            dfs(o + 1, c, n, tmp);
            tmp.pop_back();
        }

        if (o > c) {
            tmp.push_back(')');
            dfs(o, c + 1, n, tmp);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        std::string tmp;
        int opened{}, closed{};
        dfs(opened, closed, n, tmp);

        return res;
    }
};
